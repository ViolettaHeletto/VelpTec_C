// b) Struct- und Bit-Flags-Design 
#include <stdio.h>

int main(void){
    return 0;
}
/* sensor.h */ 
#include <stdint.h> 

typedef struct { 
    int       timestamp;     /* Unix-artiger Integer-Zeitstempel */ 
    double    temperature;   /* °C — double für ~15 signifikante Stellen Präzision */ 
    double    humidity;      /* % relative Luftfeuchtigkeit — double für Präzision */ 
    uint8_t   flags;         /* 8 unabhängige Bit-Flags — uint8_t ist exakt 8-Bit */ 
} SensorReading; 

// Typbegründung: 

// uint8_t für flags: Das Feld packt bis zu 8 boolesche Statusbits in ein Byte. Ein vorzeichenloser Typ mit fester Breite aus <stdint.h> ist erforderlich, weil bitweise Operationen auf vorzeichenbehafteten Typen implementierungsdefiniertes Verhalten für Right-Shifts haben und potenziell undefiniertes Verhalten für Left-Shifts. 

// double für Temperatur und Luftfeuchtigkeit: Physikalische Messungen profitieren von der ~15-stelligen Präzision von double und seinem größeren Wertebereich. float (~7 Stellen) kann bei akkumulierten Berechnungen an Präzision verlieren. 

// Bit-Flag-Makros: 

#define FLAG_VALID       (1u << 0)   /* Bit 0: Messung ist gültig */ 
#define FLAG_HUMID_HIGH  (1u << 1)   /* Bit 1: Luftfeuchtigkeit > 80% */ 
#define FLAG_TEMP_ALARM  (1u << 2)   /* Bit 2: Temperatur > 40,0°C */ 
// Setzen, Testen und Löschen von FLAG_TEMP_ALARM auf der Variable r: 

// // /* FLAG_TEMP_ALARM setzen */ 
// r.flags |= FLAG_TEMP_ALARM; 
 
// /* FLAG_TEMP_ALARM testen */ 
// if (r.flags & FLAG_TEMP_ALARM) { 
//     fprintf(stderr, "Temperature alarm!\n"); 
// } 
 
// /* FLAG_TEMP_ALARM löschen */ 
// r.flags &= ~FLAG_TEMP_ALARM; 

// Das Muster ~FLAG_TEMP_ALARM invertiert die Maske, sodass nur Bit 2 zu 0 wird; die AND-Operation löscht dieses Bit, ohne andere Flags zu berühren. 

// Form 

// c) Design des dynamischen Arrays 

// typedef struct { 
//     SensorReading *data;    /* Zeiger auf heap-allokiertes Array */ 
//     size_t         count;   /* Anzahl der aktuell gespeicherten Messungen */ 
//     size_t         capacity; /* Anzahl der allokierten Slots */ 
// } SensorLog; 
// add_reading-Pseudocode: 

// int add_reading(SensorLog *log, SensorReading reading) { 
//     /* Falls voll, Kapazität verdoppeln */ 
//     if (log->count == log->capacity) { 
//         size_t new_cap = log->capacity * 2; 
//         SensorReading *tmp = realloc(log->data, 
//                                      new_cap * sizeof(SensorReading)); 
//         if (tmp == NULL) { 
//             /* realloc fehlgeschlagen: originales log->data noch gültig, Fehler melden */ 
//             fprintf(stderr, "add_reading: realloc failed\n"); 
//             return -1; 
//         } 
//         log->data     = tmp;    /* Zeiger nur bei Erfolg aktualisieren */ 
//         log->capacity = new_cap; 
//     } 
//     log->data[log->count] = reading; 
//     log->count++; 
//     return 0;   /* Erfolg */ 
// } 

// Kritische realloc-Fehlerbehandlung: 

// Wenn realloc NULL zurückgibt, wird die ursprüngliche Allokation nicht freigegeben – der vorhandene Datenzeiger bleibt gültig. Deshalb muss der Rückgabewert in einer temporären Variable (tmp) gespeichert werden, bevor er zurück an log->data zugewiesen wird. Wenn du log->data = realloc(log->data, ...) direkt schreiben würdest und realloc fehlschlägt, würdest du den einzigen Zeiger auf die vorhandenen Daten mit NULL überschreiben und alle bisher gesammelten Messungen dauerhaft verlieren. 

// Form 

// d) Datei-I/O-Plan 

// Dateimodus: Verwende "wb" zum Schreiben und "rb" zum Lesen. 

// Das b-Flag schaltet in den Binärmodus, der unter Windows die Zeilenumbruchübersetzung verhindert (Konvertierung von \n in \r\n beim Schreiben). Ohne b könnte ein rohes Byte mit dem Wert 0x0A in einem double-Feld unter Windows still beschädigt werden. Auf POSIX-Systemen wird b akzeptiert, aber ignoriert; seine Einbeziehung macht den Code portabel. 

// Funktionssignaturen: 

// int write_log(const SensorLog *log, const char *path); 
// int read_log(SensorLog *log, const char *path); 
// Beide geben bei Erfolg 0 und bei Fehler -1 zurück, gemäß der Unix-Konvention. 

// fwrite/fread-Aufrufe und Rückgabewertprüfungen: 

// /* Schreiben */ 
// size_t written = fwrite(log->data, 
//                         sizeof(SensorReading), 
//                         log->count, 
//                         f); 
// if (written != log->count) { 
//     fprintf(stderr, "write_log: wrote %zu of %zu records\n", 
//             written, log->count); 
//     fclose(f); 
//     return -1; 
// } 
 
// /* Lesen — zuerst die am Dateianfang gespeicherte Anzahl lesen */ 
// size_t count; 
// if (fread(&count, sizeof(size_t), 1, f) != 1) { 
//     fprintf(stderr, "read_log: could not read record count\n"); 
//     fclose(f); 
//     return -1; 
// } 
// /* allokieren, dann Datensätze lesen */ 
// SensorReading *buf = malloc(count * sizeof(SensorReading)); 
// if (fread(buf, sizeof(SensorReading), count, f) != count) { ... } 

// fwrite und fread geben beide die Anzahl der erfolgreich übertragenen Elemente (nicht Bytes) zurück. Der Vergleich mit der erwarteten Anzahl erkennt kurze Schreibvorgänge durch volle Datenträger und kurze Lesevorgänge durch abgeschnittene Dateien. 

// Form 

// e) Header-Datei mit Guards und bedingter Kompilierung 

// /* include/sensor.h */ 
// #ifndef SENSOR_H 
// #define SENSOR_H 
 
// #include <stdint.h> 
// #include <stddef.h>   /* size_t */ 
// #include <stdio.h> 
 
// /* --- Status-Bit-Flags --- */ 
// #define FLAG_VALID       (1u << 0) 
// #define FLAG_HUMID_HIGH  (1u << 1) 
// #define FLAG_TEMP_ALARM  (1u << 2) 
 
// /* --- Datentypen --- */ 
// typedef struct { 
//     int      timestamp; 
//     double   temperature; 
//     double   humidity; 
//     uint8_t  flags; 
// } SensorReading; 
 
// typedef struct { 
//     SensorReading *data; 
//     size_t         count; 
//     size_t         capacity; 
// } SensorLog; 
 
// /* --- Funktionsprototypen --- */ 
// int  add_reading(SensorLog *log, SensorReading reading); 
// int  write_log(const SensorLog *log, const char *path); 
// int  read_log(SensorLog *log, const char *path); 
// void free_log(SensorLog *log); 
 
// /* --- Debug-Ausgabe (nur kompiliert wenn -DDEBUG übergeben wird) --- */ 
// #ifdef DEBUG 
// #define LOG_DEBUG(msg) \ 
//     fprintf(stderr, "[DEBUG] %s:%d: " msg "\n", __FILE__, __LINE__) 
// #else 
// #define LOG_DEBUG(msg)   /* No-Op in Release-Builds */ 
// #endif 
 
// #endif /* SENSOR_H */ 

// Der #ifndef SENSOR_H-Guard am Anfang und #endif am Ende stellen sicher, dass der Inhalt nur einmal pro Übersetzungseinheit verarbeitet wird, auch wenn mehrere Quelldateien diesen Header einbinden. Der #ifdef DEBUG-Block kompiliert ein diagnostisches Makro nur ein, wenn der Entwickler -DDEBUG in der Kommandozeile übergibt; in Release-Builds expandiert das Makro zu nichts und fügt keinerlei Overhead hinzu. 

// Form 

// f) Makefile 

// CC      = gcc 
// CFLAGS  = -Wall -Wextra -std=c23 -Iinclude 
// # Um Debug-Ausgabe zu aktivieren: make CFLAGS="-Wall -Wextra -std=c23 -Iinclude -DDEBUG" 
// LDFLAGS = 
// TARGET  = sensor_logger 
// OBJECTS = src/main.o src/sensor.o 
 
// .PHONY: clean all 
 
// all: $(TARGET) 
 
// $(TARGET): $(OBJECTS) 
//     $(CC) $(OBJECTS) -o $(TARGET) $(LDFLAGS) 
 
// src/main.o: src/main.c include/sensor.h 
//     $(CC) $(CFLAGS) -c src/main.c -o src/main.o 
 
// src/sensor.o: src/sensor.c include/sensor.h 
//     $(CC) $(CFLAGS) -c src/sensor.c -o src/sensor.o 
 
// clean: 
//     rm -f $(TARGET) $(OBJECTS) 



// Wichtige Punkte: 

// CC und CFLAGS als Variablen ermöglichen den Wechsel zu Clang mit einer Änderung (CC = clang). 

// Jede .o-Regel listet include/sensor.h als Voraussetzung auf, sodass Make die Übersetzungseinheit neu kompiliert, wenn sich der Header ändert. 

// clean ist .PHONY, damit es immer ausgeführt wird, unabhängig davon, ob eine Datei namens clean existiert. 

// Ein Entwickler aktiviert den Debug-Modus durch Überschreiben von CFLAGS in der Kommandozeile: make CFLAGS="... -DDEBUG". 