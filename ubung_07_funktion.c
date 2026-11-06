// Übung 07.2.Ü.01
// Abschlussbedingungen
//  Erledigt: Anzeigen
// Aufgabe: Funktionen mit Arrays und Strings schreiben und verwenden
// Wende dein Wissen über Funktionen und Arrays an, indem du ein kleines C-Programm implementierst, das eine Liste von Studierendennamen verarbeitet.

// Dir liegt folgendes Namensarray vor:

// char names[5][30] = {
//     "Alice",
//     "bob",
//     "CHARLIE",
//     "diana",
//     "Eve"
// };
// a) Schreibe eine Funktion void normalize_name(char *name), die das erste Zeichen eines Namens in einen Großbuchstaben und alle verbleibenden Zeichen in Kleinbuchstaben umwandelt. Verwende Funktionen aus <ctype.h> für die Umwandlungen. Wende den sicheren Cast (unsigned char) beim Aufruf von <ctype.h>-Funktionen an.

// b) Schreibe eine Funktion void print_names(char names[][30], int count), die über das Array iteriert und jeden Namen auf einer eigenen Zeile mit printf ausgibt. Die Funktion muss die Array-Größe als separaten Parameter entgegennehmen.

// c) Rufe in main für jeden Namen im Array normalize_name auf und rufe dann print_names auf, um das Endergebnis anzuzeigen. Schreibe für jede Funktion einen Funktionsprototyp am Anfang der Datei, vor main.
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <ctype.h>

void normalize_name(char *name);
void print_names(char names[][30], size_t count);

int main(void){
    char names[5][30] = {
        "Alice",
        "bob",
        "CHARLIE",
        "diana",
        "Eve"
    };

    for (int i = 0; i < 5; i++){
        normalize_name(names[i]);
    }
    print_names(names, sizeof names / sizeof names[0]);
    return 0;
}

void normalize_name(char *name){
    if (name == NULL || name[0] == '\0') return; // защита от пустой строки
    name[0] = (char)toupper((unsigned char)name[0]);
    for (int i = 1; name[i] != '\0'; i++) {
        name[i] = (char)tolower((unsigned char)name[i]);
    }
}

void print_names(char names[][30], size_t count){
    for (size_t  i = 0; i < count; i++){
        printf("%s\n", names[i]);
    }
}

/* [[nodiscard]]
#include <stdio.h>

[[nodiscard]] int open_file(const char *path) {
    if (path == NULL) return -1;
    FILE *f = fopen(path, "r");
    if (f == NULL) return -1;
    fclose(f);
    return 0;
}

int main(void) {
    // ❌ Предупреждение компилятора:
    // warning: ignoring return value of 'open_file' declared with 'nodiscard'
    open_file("test.txt");

    // ✅ Правильно: результат используется
    int rc = open_file("test.txt");
    if (rc != 0) {
        printf("Ошибка открытия файла\n");
    }

    // ✅ Явное отбрасывание — предупреждения НЕ будет
    (void)open_file("test.txt");

    return 0;
}*/