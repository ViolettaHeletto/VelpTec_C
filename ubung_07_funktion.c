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
// Übung 07.2.Ü.02
// Abschlussbedingungen
//  Erledigt: Anzeigen
// Aufgabe: Funktionen, Arrays und Schleifen gemeinsam anwenden
// Wende dein Wissen über Funktionen, Arrays und Schleifen an, um eine kleine Sammlung von Hilfsfunktionen in C zu implementieren. Jede Teilaufgabe konzentriert sich auf eine andere Kombination der bisher gelernten Konzepte.

// Schreibe für jede Teilaufgabe eine vollständige Funktion mit dem korrekten Prototyp und der Funktionsdefinition und zeige ihre Verwendung mit einer kurzen main-Funktion.

// a) Implementiere eine Funktion int find_max(int arr[], int size), die ein Integer-Array und seine Größe als Parameter entgegennimmt und das größte Element zurückgibt. Deklariere in main ein Integer-Array mit mindestens fünf Werten, rufe find_max auf und gib das Ergebnis aus. Erkläre in einem Kommentar, warum size als separater Parameter übergeben werden muss.

// b) Implementiere eine Funktion int count_vowels(char str[]), die die Anzahl der Vokale (a, e, i, o, u — sowohl Groß- als auch Kleinbuchstaben) in einem gegebenen String zählt und zurückgibt. Verwende eine for-Schleife, um über die Zeichen zu iterieren, und eine switch-Anweisung, um zu prüfen, ob jedes Zeichen ein Vokal ist. Rufe die Funktion in main mit zwei verschiedenen Strings auf und gib beide Ergebnisse aus.

// c) Implementiere eine Funktion void print_even(int limit), die alle geraden Zahlen von 2 bis einschließlich limit (wenn limit gerade ist) mithilfe einer for-Schleife und der continue-Anweisung zum Überspringen ungerader Zahlen ausgibt. Deklariere den Funktionsprototyp vor main und platziere die Definition nach main. Rufe in main print_even(10) auf.
/////////////////////////////////////////////////////////////////////////////////////////
// Übung 07.4.Ü.01
// Abschlussbedingungen
//  Erledigt: Anzeigen
// Aufgabe: Funktionszeiger und Callbacks verstehen
// Erkläre das Konzept der Funktionszeiger in C und beschreibe, wie sie verwendet werden, um Callbacks zu implementieren. Beantworte die folgenden Fragen auf Basis dessen, was du über Funktionen und Funktionszeiger gelernt hast.

// a) Beschreibe, was ein Funktionszeiger in C ist. Erkläre den Unterschied zwischen den folgenden zwei Deklarationen und gib an, welche einen Funktionszeiger und welche eine Funktion deklariert:

// int *compare(int a, int b);
// int (*compare)(int a, int b);
// b) Erkläre, was ein Callback ist und wie Funktionszeiger Callbacks ermöglichen. Beschreibe eine konkrete Situation aus der C-Standardbibliothek, in der ein Callback verwendet wird, und erkläre, warum dieses Design sinnvoll ist.

// c) Vergleiche die beiden Ansätze in der folgenden Tabelle. Fülle für jede Zeile die fehlende Beschreibung aus, indem du erklärst, wie Funktionszeiger und typedef zusammenwirken und welches Problem typedef löst.


// d) Erkläre die Regeln für variadic Funktionen in C. Beschreibe die Rolle jedes der folgenden Elemente: die ...-Ellipse in der Parameterliste, va_start, va_arg und va_end. Nenne eine wichtige Einschränkung von variadic Funktionen bezüglich Typsicherheit.
/////////////////////////////////////////////////////////////////////////////////////////
// Übung 07.4.Ü.02
// Abschlussbedingungen
//  Erledigt: Anzeigen
// Aufgabe: Funktionen, Schleifen und Arrays gemeinsam anwenden
// Wende dein Wissen über Funktionen, Schleifen und Arrays an, indem du ein kleines Zahlenverarbeitungsprogramm in C implementierst.

// Schreibe ein vollständiges C-Programm, das die folgenden Aufgaben ausführt:

// a) Definiere eine Funktion int count_evens(int arr[], int size), die ein Integer-Array und seine Größe als Parameter entgegennimmt und die Anzahl der geraden Zahlen im Array zurückgibt.

// b) Definiere eine Funktion double compute_average(int arr[], int size), die ein Integer-Array und seine Größe entgegennimmt und den Durchschnitt aller Elemente als double zurückgibt. Verwende einen expliziten Cast, um Gleitkomma-Division sicherzustellen.

// c) Definiere eine Funktion void print_above_average(int arr[], int size, double avg), die alle Elemente des Arrays ausgibt, die strikt größer als der gegebene Durchschnitt sind, jeweils auf einer eigenen Zeile.

// d) Deklariere und initialisiere in main ein Integer-Array mit den Werten {12, 7, 3, 18, 5, 22, 9, 14, 6, 11}. Rufe alle drei Funktionen auf und gib die Ergebnisse in einem klaren, beschrifteten Format mithilfe von printf aus.

// Schreibe Funktionsprototypen für alle drei Funktionen am Anfang deiner Datei, vor main.
/////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <ctype.h>

void normalize_name(char *name);
void print_names(char names[][30], size_t count);

int find_max(int arr[], size_t size);
int count_vowels(char str[]);
void print_even(int limit);

int count_evens(int arr[], int size);
double compute_average(int arr[], int size);
void print_above_average(int arr[], int size, double avg);

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

/////////////////////////////////////////////////////////////////////////////////////////
    int numbers[10] = {-3, 6, 568, 238, -45, 548, 6, 0, 56, 56};
    int arr_max = find_max(numbers, sizeof numbers / sizeof numbers[0]);
    printf("%d ", arr_max);

    char str[] = "oidvoei";
    printf("%d ", count_vowels(str));

    print_even(10);
/////////////////////////////////////////////////////////////////////////////////////////

    count_evens(numbers, 10);
    printf("%.2f ",compute_average(numbers, 10));
    printf("\n");
    print_above_average(numbers, 10, compute_average(numbers, 10));

    return 0;
}

void print_above_average(int arr[], int size, double avg){
    for(int i = 0; i < size; i++){
        if(arr[i] > avg){
            printf("%d\n", arr[i]);
        }
    }
}

double compute_average(int arr[], int size){
    int sum = 0;
    for(int i = 0; i < size; i++){
        sum += arr[i];
    }
    return (double)sum / size;
}

int count_evens(int arr[], int size){
    int count = 0;
    for(int i = 0; i < size; i++){
        if (i % 2 == 0) {
            ++count;
        }
    }
    return count;
}

void print_even(int limit){
    for(int i = 2; i <= limit; i++){
        if (i % 2 != 0) {
            continue; // gerade Zahlen überspringen
        }
        printf("%d ", i); // nur ungerade Zahlen erreichen diese Zeile
    }
}

int count_vowels(char str[]){
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++){
        switch (str[i]){
            case 'a': case 'e': case 'i': case 'o': case 'u':
            count++;
            default:
            break;
        }
    }
    return count;
}

 int find_max(int arr[], size_t size){
    int max = arr[0];
    for(size_t i = 0; i < size; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    return max;
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



/////////////////////////////////////////////////////////////////////////////////////////
// Case Study 07.4.C.01
// Abschlussbedingungen
//  Erledigt: Anzeigen
// Aufgabe: Einen Studierenden-Notenmanager mit Funktionen und Arrays erstellen
// Du arbeitest als Junior-C-Entwickler bei einem kleinen Unternehmen für Bildungssoftware. Dein Team hat die Aufgabe, ein Kommandozeilen-Tool zu erstellen, das Studierenden-Noten für eine Universitätsabteilung verwaltet. Das Tool soll Studierendennamen und ihre Prüfungspunkte speichern, Statistiken berechnen und eine einfache Suchfunktion bereitstellen. Dein Teamleiter hat dich gebeten, dies mithilfe von Funktionen, Arrays und Strings zu implementieren — und dabei alle guten Praktiken anzuwenden, die du bisher gelernt hast.

// Das Programm soll bis zu 5 Studierende verwalten. Jede Person hat einen Namen (bis zu 49 Zeichen) und einen Integer-Punktestand (0–100).

// Deine Aufgabe: Implementiere die folgenden vier Funktionen und eine main-Funktion, die zeigt, wie sie zusammenarbeiten.

// a) Schreibe eine Funktion void print_student(char name[], int score), die den Namen und den Punktestand eines einzelnen Studierenden im Format: Name: Alice | Score: 87 ausgibt. Die Funktion muss einen Funktionsprototyp verwenden, der vor main deklariert wird.

// b) Schreibe eine Funktion double calculate_average(int scores[], int count), die ein Array mit Integer-Punkteständen und die Anzahl der Elemente entgegennimmt und den Durchschnitt als double zurückgibt. Verwende diese Funktion in main, um den Klassendurchschnitt auf zwei Dezimalstellen formatiert auszugeben.

// c) Schreibe eine Funktion int find_highest(int scores[], int count), die den höchsten Punktestand im Array zurückgibt. Verwende eine Schleife, um alle Elemente zu durchsuchen. Rufe diese Funktion in main auf und gib das Ergebnis aus.

// d) Deklariere in main ein zweidimensionales Zeichen-Array char names[5][50] für bis zu 5 Studierendennamen und ein separates Integer-Array int scores[5] für ihre Punktestände. Initialisiere beide Arrays mit den folgenden Daten und rufe dann die Funktionen aus den Teilaufgaben a), b) und c) auf, um den vollständigen Bericht anzuzeigen:
/////////////////////////////////////////////////////////////////////////////////////////
// #include <stdio.h>
// #include <string.h>

// // --- Function prototypes ---
// void print_student(char name[], int score);
// double calculate_average(int scores[], int count);
// int find_highest(int scores[], int count);

// // --- Function definitions ---

// void print_student(char name[], int score) {
//     printf("Name: %s | Score: %d\n", name, score);
// }
// double calculate_average(int scores[], int count) {
//     int total = 0;
//     for (int i = 0; i < count; i++) {
//         total += scores[i];
//     }
//     return (double)total / count;
// }
// int find_highest(int scores[], int count) {
//     int highest = scores[0];
//     for (int i = 1; i < count; i++) {
//         if (scores[i] > highest) {
//             highest = scores[i];
//         }
//     }
//     return highest;
// }
// int main(void) {
//     char names[5][50] = {
//         "Alice", "Bob", "Carla", "David", "Eva"
//     };
//     int scores[5] = {87, 73, 95, 61, 82};
//     int count = 5;

//     printf("=== Student Grade Report ===\n");
//     for (int i = 0; i < count; i++) {
//        print_student(names[i], scores[i]);
//     }

//     double avg = calculate_average(scores, count);
//     int top = find_highest(scores, count);

//     printf("\nClass Average: %.2f\n", avg);
//     printf("Highest Score: %d\n", top);

//     return 0;
// }
