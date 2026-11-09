// Teilprüfung 2
// Abschlussbedingungen
// Zu erledigen: Abgabe einreichen Zu erledigen: Eine Bewertung erhalten
// K4.0021_4.0_08.2.A.01

// Aufgabe

// Du schreibst ein kleines C-Hilfsprogramm, das eine Liste von Studierendendatensätzen verarbeitet. Jeder Datensatz besteht aus einem Studierendennamen (String) und einem ganzzahligen Punktestand. Deine Aufgabe integriert Themen aus dem gesamten Kurs — Variablen, Arrays, Strings, Schleifen, Bedingungen, Funktionen und Zeiger — in ein einziges kohärentes Programmdesign. 

// Das Hilfsprogramm muss die folgenden Funktionen bereitstellen:

// a) Score-Normalisierungsfunktion: Schreibe eine Funktion void normalize_scores(int *scores, int count, int *out_min, int *out_max), die ein Array mit ganzzahligen Punkteständen und seine Länge entgegennimmt und über Zeigerparameter den minimalen und maximalen gefundenen Punktestand zurückgibt. Analysiere, wie Call-by-Reference über Zeiger es dieser Funktion ermöglicht, zwei Ergebnisse gleichzeitig zurückzugeben, und erkläre, warum void normalize_scores(int scores[], int count, int min, int max) für denselben Zweck NICHT funktionieren würde. 

// b) Namensvalidierungsfunktion: Schreibe eine Funktion int is_valid_name(const char *name), die 1 (wahr) zurückgibt, wenn der Name gültig ist, und 0 (falsch), wenn nicht. Ein gültiger Name muss: 

// Nicht leer sein (Länge > 0)
// Nur alphabetische Zeichen und Leerzeichen enthalten (verwende isalpha und isspace aus <ctype.h>)

// Nicht länger als 49 Zeichen sein

// Erkläre die Verwendung von const char * im Parameter und warum dies dem Aufrufer einen Vertrag signalisiert.

// c) Notenklassifizierung: Schreibe eine Funktion const char *grade_label(int score), die eine switch-Anweisung (oder eine if-else-if-Kette) verwendet, um den passenden Notenlabel-String basierend auf der folgenden Skala zurückzugeben: 

//  Punktebereich
//  Label
// 90 - 100 “A”
// 80 - 89  “B”
// 70 - 79  “C”
// 60 - 69 “D”
// 0 - 59 “F”

// d) Integration und Analyse: Schreibe eine main-Funktion, die alles zusammenfügt:
// Deklariere ein Array mit 4 Studierendennamen (als char-Arrays mit je einem Puffer von 50 Zeichen) und ein passendes Array mit 4 ganzzahligen Punkteständen. Befülle sie mit fest kodierten Werten deiner Wahl. 

// Validiere jeden Namen mit is_valid_name. Wenn ein Name ungültig ist, gib eine Warnung aus und überspringe den Datensatz.

// Rufe normalize_scores auf dem Punktestand-Array auf und gib den minimalen und maximalen Punktestand aus.

// Durchlaufe alle gültigen Datensätze und gib den Namen jedes Studierenden sowie seinen Notenlabel aus grade_label aus.

// Analysiere die Rolle jeder verwendeten Technik (Zeigerparameter, const char *, an Funktionen übergebene Arrays, Längenchecks für Strings) und erkläre, was fehlen oder falsch wäre, wenn jede davon entfernt oder falsch ersetzt würde. 

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NUMBER_OF_STUDENTS 4
#define NAME_LEN 50

void normalize_scores(int *scores, int count, int *out_min, int *out_max);
int is_valid_name(const char *name);
const char *grade_label(int score);

int main(void){
        char names[NUMBER_OF_STUDENTS][NAME_LEN] = {
        "Alisa",
        "Nevill",
        "Erd45f",   /* absichtlich ungültig (Ziffern) */
        "Norbert"
    };

    int scores[NUMBER_OF_STUDENTS] = { 91, 68, 75, 84 };

    int min = scores[0];
    int max = scores[0];
    normalize_scores(scores, NUMBER_OF_STUDENTS, &min, &max);
    printf("Min: %d, Max: %d\n\n", min, max);

    for (int i = 0; i < NUMBER_OF_STUDENTS; i++) {
        if (!is_valid_name(names[i])) {
            printf("Warning: Record %d ('%s') is invalid and will be skipped.\n",
                   i, names[i]);
            continue;
        }
        printf("%-10s -> %s\n", names[i], grade_label(scores[i]));
    }

    return 0;
}

void normalize_scores(int *scores, int count, int *out_min, int *out_max){
    // Call-by-Reference: *out_min/*out_max schreiben direkt in die Variablen
    // des Aufrufers, darum können zwei Ergebnisse zurückgegeben werden.
    // Mit "int min, int max" (Call-by-Value) wären es nur Kopien -> kein Effekt.
    for(int i = 0; i < count; i++){
        if (scores[i] < *out_min)
        {
            *out_min = scores[i];
        }
        if (scores[i] > *out_max)
        {
            *out_max = scores[i];
        }
    }
}

int is_valid_name(const char *name){
    // const char * = Vertrag: Funktion ändert den String nicht.
    // Darum kann man auch String-Literale übergeben.
    size_t size = strlen(name);
    if(size == 0 || size > 49){
        printf("The name length is invalid (less than 0 or greater than 50)!\n");
        return 0;
    }
    for(size_t  i = 0; i < size; i++){
        if (!isalpha(name[i]) && !isspace(name[i])){
            printf("The entered character is not a letter or a space!\n");
            return 0;
        }
    }
    return 1;
}

const char *grade_label(int score)
{
    if (score < 0 || score > 100) {
        return "Invalid score\n";
    } else if (score >= 90) {
        return "A";
    } else if (score >= 80) {
        return "B";
    } else if (score >= 70) {
        return "C";
    } else if (score >= 60) {
        return "D";
    } else {
        return "F";
    }
}