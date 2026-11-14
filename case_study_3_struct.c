/*
Case Study 10.4.C.01
Abschlussbedingungen
 Erledigt: Anzeigen
Aufgabe: Ein Geräte-Konfigurationsmodul mit Bitfeldern entwerfen

Du arbeitest als Junior-Entwickler für eingebettete Systeme bei einem Unternehmen, das kleine industrielle Sensorknoten baut. Jeder Knoten stellt ein einzelnes Konfigurationsregister bereit, dessen Bits vier unabhängige Funktionen steuern: ob das Gerät aktiviert ist, ob ausführliches Logging eingeschaltet ist, ob ein Alarmzustand aktiv ist und ob sich das Gerät im Schlafmodus befindet. Dein Team hat beschlossen, dieses Register in C über ein Struct-Bitfeld abzubilden, damit sich einzelne Flags als benannte Felder lesen und schreiben lassen — ganz ohne manuelles Bit-Gefummel.

Deine Aufgabe ist es, das Konfigurationsmodul vollständig in einer einzigen C-Quelldatei zu entwerfen. Du definierst die Datentypen, schreibst die Hilfsfunktionen und demonstrierst das Modul mit einer kurzen main-Funktion. Halte alles in einer einzigen Übersetzungseinheit — keine getrennten Header- oder Quelldateien.

a) Definiere ein typedef-Struct DeviceConfig, das Bitfelder verwendet, um die vier booleschen Flags zu speichern. Jedes Flag — enabled, verbose, alarm und sleep_mode — soll genau 1 Bit belegen. Definiere außerdem ein C23-typisiertes Enum DeviceMode : unsigned char mit mindestens drei Zuständen: MODE_NORMAL, MODE_DIAGNOSTIC und MODE_STANDBY. Erkläre in einem kurzen Kommentar neben jedem Bitfeld, warum 1-Bit-unsigned-Mitglieder hier die richtige Wahl sind.

b) Schreibe die folgenden drei Funktionen, die über einen Zeiger auf DeviceConfig arbeiten:

void cfg_enable(DeviceConfig *cfg) — setzt enabled auf 1 und sleep_mode auf 0 (das Aktivieren des Geräts weckt es aus dem Schlaf)
void cfg_sleep(DeviceConfig *cfg) — setzt sleep_mode auf 1 und enabled auf 0
void cfg_print(const DeviceConfig *cfg, DeviceMode mode) — gibt den aktuellen Wert jedes Flags und den aktiven Gerätemodus als menschenlesbare Zeichenkette aus
Alle drei Funktionen müssen sich gegen einen NULL-Zeiger absichern und sofort zurückkehren, wenn cfg gleich NULL ist.

c) Schreibe eine main-Funktion, die:

Ein DeviceConfig auf dem Stack deklariert und alle Felder mit einem benannten Initialisierer (designated initializer) mit null vorbelegt.
cfg_print aufruft, um den Ausgangszustand anzuzeigen (Modus: MODE_NORMAL).
cfg_enable aufruft und verbose direkt über Feldzugriff auf 1 setzt.
cfg_print erneut aufruft (Modus: MODE_DIAGNOSTIC).
cfg_sleep aufruft.
cfg_print ein letztes Mal aufruft (Modus: MODE_STANDBY), um die Zustandsänderung zu bestätigen.
*/
/////////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>

/* Definiere ein typedef-Struct DeviceConfig, das Bitfelder verwendet,
um die vier booleschen Flags zu speichern. Jedes Flag — enabled, verbose,
alarm und sleep_mode — soll genau 1 Bit belegen. Definiere außerdem ein C23-typisiertes
Enum DeviceMode : unsigned char mit mindestens drei Zuständen: MODE_NORMAL,
MODE_DIAGNOSTIC und MODE_STANDBY. Erkläre in einem kurzen Kommentar neben
jedem Bitfeld, warum 1-Bit-unsigned-Mitglieder hier die richtige Wahl sind.*/
typedef enum : unsigned char {MODE_NORMAL, MODE_DIAGNOSTIC, MODE_STANDBY} DeviceMode;

typedef struct {
    unsigned enabled   : 1;  /* 1-Bit-Flag: Gerät aktiv (nur 0 oder 1)    */
    unsigned verbose   : 1;  /* 1-Bit-Flag: ausführliches Logging an/aus  */
    unsigned alarm     : 1;  /* 1-Bit-Flag: Alarmzustand aktiv            */
    unsigned sleep_mode: 1;  /* 1-Bit-Flag: Gerät im Schlafmodus          */
} DeviceConfig;
/* ── Hilfsfunktion: Enum auf druckbare Zeichenkette abbilden ──── */

static const char *mode_name(DeviceMode m) {
    switch (m) {
        case MODE_NORMAL:     return "NORMAL";
        case MODE_DIAGNOSTIC: return "DIAGNOSTIC";
        case MODE_STANDBY:    return "STANDBY";
        default:              return "UNKNOWN";
    }
}

void cfg_enable(DeviceConfig *cfg);
void cfg_sleep(DeviceConfig *cfg);
void cfg_print(const DeviceConfig *cfg, DeviceMode mode);

int main(void){
    /* Schritt 1: mit einem benannten Initialisierer mit null vorbelegen */
    DeviceConfig
    cfg = {
        .enabled    = 0,
        .verbose    = 0,
        .alarm      = 0,
        .sleep_mode = 0
    };

    /* Schritt 2: Ausgangszustand */
    cfg_print(&cfg, MODE_NORMAL);

    /* Schritt 3: Gerät aktivieren und verbose einschalten */
    cfg_enable(&cfg);
    cfg.verbose = 1;           /* direkter Feldzugriff — keine Bitmaske nötig */

    /* Schritt 4: Diagnose-Ansicht */
    cfg_print(&cfg, MODE_DIAGNOSTIC);

    /* Schritt 5: Gerät schlafen legen */
    cfg_sleep(&cfg);

    /* Schritt 6: Standby-Ansicht — enabled sollte 0 sein, sleep_mode 1 */
    cfg_print(&cfg, MODE_STANDBY);

    return 0;
}

void cfg_enable(DeviceConfig *cfg){
    cfg->enabled = 1;
    cfg->sleep_mode = 0;
}

void cfg_sleep(DeviceConfig *cfg){
    cfg->sleep_mode = 1;
    cfg->enabled = 0;
}

void cfg_print(const DeviceConfig *cfg, DeviceMode mode) {
    if (cfg == NULL) return;   /* NULL-Absicherung */
    printf("--- Device Config (mode: %s) ---\n", mode_name(mode));
    printf("  enabled   : %u\n", cfg->enabled);
    printf("  verbose   : %u\n", cfg->verbose);
    printf("  alarm     : %u\n", cfg->alarm);
    printf("  sleep_mode: %u\n\n", cfg->sleep_mode);
}