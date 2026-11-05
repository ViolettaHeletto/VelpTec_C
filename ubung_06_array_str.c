// Übung 06.2.Ü.01
// Abschlussbedingungen
//  Erledigt: Anzeigen
// Aufgabe: Mit Arrays und Strings in C arbeiten
// Deklariere und arbeite mit eindimensionalen Integer-Arrays und C-Strings. Wende for-Schleifen an, um über Array-Elemente zu iterieren, Aggregatwerte zu berechnen und String-Inhalte mithilfe der Standard-String-Funktionen strlen, strcpy und strcmp zu verarbeiten.

// Teil 1: Integer-Array-Operationen

// a) Deklariere ein Integer-Array namens temperatures mit 7 Elementen und initialisiere es mit den folgenden Werten: 18, 22, 19, 25, 30, 27, 21. Schreibe eine for-Schleife, die die Summe aller Elemente berechnet und ausgibt. Erweitere dann dein Programm, um den Maximalwert im Array zu finden und auszugeben.

// b) Deklariere ein zweites Array namens hot_days mit 7 Elementen, die alle mit null initialisiert sind. Schreibe eine for-Schleife, die alle Elemente aus temperatures in hot_days kopiert, die größer oder gleich 24 sind. Gib alle Elemente von hot_days nach der Schleife aus.

// Teil 2: String-Operationen

// c) Deklariere ein char-Array namens city mit genügend Platz für den String "Berlin". Gib die logische Länge des Strings mit strlen und die insgesamt belegte Größe mit sizeof aus. Erkläre in einem Kommentar, warum die beiden Werte unterschiedlich sind.

// d) Deklariere ein zweites char-Array namens capital mit einer Puffergröße von 20. Verwende strcpy, um den Inhalt von city in capital zu kopieren. Verwende dann strcmp, um beide Strings zu vergleichen, und gib aus, ob sie gleich sind oder nicht.

// e) Schreibe eine for-Schleife, die über die Zeichen von city iteriert und jedes Zeichen zusammen mit seinem Index in einer eigenen Zeile ausgibt (z. B. [0]: B). Verwende den Null-Terminator '\0' als Stoppbedingung der Schleife.

// C-Compiler (z. B. gcc)
// Standard-Header: <stdio.h>, <string.h>
/////////////////////////////////////////////////////////////////////////////////////////

// Übung 06.2.Ü.02
// Abschlussbedingungen
//  Erledigt: Anzeigen
// Aufgabe: Arrays mit Schleifen und Bedingungen verarbeiten
// Wende an, was du über Arrays, Schleifen, Bedingungen und Datentypen gelernt hast, um eine kleine Sammlung von Integer-Werten zu analysieren.

// Dir liegt folgendes Array mit Prüfungsergebnissen (von 100 möglichen Punkten) vor:

// Schreibe ein vollständiges C-Programm, das dieses Array deklariert und anschließend folgende Aufgaben erfüllt:

// a) Berechne und gib den Durchschnittswert als Gleitkommazahl mit genau zwei Nachkommastellen aus.

// b) Zähle und gib aus, wie viele Studierende bestanden haben (Punktzahl >= 60) und wie viele nicht bestanden haben (Punktzahl < 60).

// c) Finde und gib die höchste und niedrigste Punktzahl im Array aus.
/////////////////////////////////////////////////////////////////////////////////////////
// Übung 06.3.Ü.01
// Abschlussbedingungen
//  Erledigt: Anzeigen
// Aufgabe: Sichere String-Verarbeitung und Zeichenanalyse
// Wende sichere String-Verarbeitungstechniken an, um unsichere String-Operationen zu ersetzen, und implementiere eine zeichenbasierte Textanalyse-Routine.

// Das folgende Code-Snippet enthält mehrere unsichere String-Verarbeitungsmuster. Schreibe es um und erweitere es mithilfe der sicheren Alternativen aus Kapitel 6.3.

// Ausgangscode (unsichere Version):

// #include <stdio.h>
// #include <string.h>

// int main(void) {
//     char username[20];
//     char greeting[30];

//     printf("Enter your username: ");
//     scanf("%s", username);

//     strcpy(greeting, "Welcome, ");
//     strcat(greeting, username);
//     strcat(greeting, "!");

//     printf("%s\n", greeting);
//     return 0;
// }

// a) Identifiziere alle unsicheren String-Operationen im obigen Code und erkläre kurz, warum jede davon unsicher ist.

// b) Schreibe das Programm ausschließlich mit sicheren Alternativen um. Ersetze den scanf("%s", ...)-Aufruf durch fgets, verwende snprintf zum Aufbauen des Begrüßungsstrings und stelle sicher, dass die Ausgabe korrekt ist. Behandle dabei den abschließenden Zeilenumbruch, den fgets einfügt.

// c) Erweitere deine sichere Version um eine Schleife, die über jedes Zeichen in username iteriert und folgendes zählt:

// die Anzahl alphabetischer Zeichen (Buchstaben)
// die Anzahl von Ziffernzeichen (0–9)
// Gib beide Zähler am Ende aus. Verwende die passenden Funktionen aus <ctype.h> und wende den korrekten Cast beim Aufrufen dieser Funktionen an.

/////////////////////////////////////////////////////////////////////////////////////////
// Übung 06.3.Ü.02
// Abschlussbedingungen
//  Erledigt: Anzeigen
// Aufgabe: String-Eingaben mit Arrays verarbeiten und validieren
// Wende dein Wissen über Arrays, Strings, Schleifen und Bedingungen an, um ein C-Programm zu schreiben, das eine Liste vom Benutzer eingegebener Wörter erfasst und verarbeitet.

// Schreibe ein C-Programm, das Folgendes tut:

// a) Deklariere ein zweidimensionales Zeichenarray, das bis zu 5 Wörter mit einer maximalen Länge von jeweils 19 Zeichen (plus Null-Terminator) speichern kann. Verwende fgets, um jedes Wort vom Benutzer einzulesen, und entferne nach jedem Einlesen den abschließenden Zeilenumbruch.

// b) Iteriere nach der Eingabe aller 5 Wörter über die Liste und gib jedes Wort zusammen mit seiner Länge (mit strlen) und der Information aus, ob das erste Zeichen des Wortes ein Großbuchstabe ist (verwende isupper aus <ctype.h>). Formatiere die Ausgabe als Tabelle mit drei Spalten: das Wort, seine Länge und eine Bezeichnung, die entweder „Uppercase start” oder „Lowercase start” lautet.

//c) Zähle, wie viele der eingegebenen Wörter mit einem Großbuchstaben beginnen und wie viele mit einem Kleinbuchstaben beginnen. Gib beide Zähler am Ende aus.
/////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int aufgabe_1ab(){
    int temperatures[7] = {18, 22, 19, 25, 30, 27, 21};
    int sum = 0;
    int max = temperatures[0];
    for(int i = 0; i < 7; i++){
        sum += temperatures[i];
        if(temperatures[i] > max){
            max = temperatures[i];
        }
    }
    printf("Sum: %d\n", sum);
    printf("Maximum: %d\n", max);

    int hot_days[7] = {0};
    for(int i = 0; i < 7; i++){
        if(temperatures[i] >= 24){
            hot_days[i] = temperatures[i];
        }
    }
    printf("hot_days: ");
    for (int i = 0; i < 7; i++) {
        printf("%d ", hot_days[i]);  // 0 0 0 25 30 27 0
    }
    printf("\n");
}

int aufgabe_1cd(){
    char city[] = "Berlin";
    printf("strlen: %zu\n", strlen(city));  // 6 — logical length, no null
    printf("sizeof: %zu\n", sizeof(city));  // 7 — total bytes including '\0'

    char capital[20];
    strcpy(capital, city);  // Copies "Berlin\0" into capital

    if (strcmp(city, capital) == 0) {
        printf("Strings are equal.\n");  // Printed
    } else {
        printf("Strings are not equal.\n");
    }
     for (int i = 0; city[i] != '\0'; i++) {
        printf("[%d]: %c\n", i, city[i]);
    }

}

int aufgabe_2(){
    int scores[8] = {82, 47, 91, 55, 78, 63, 34, 88};
    int count = 8;

    /* a) Durchschnitt berechnen */
    int total = 0;
    for (int i = 0; i < count; i++) {
        total += scores[i];
    }
    double average = (double)total / count;
    printf("Average score: %.2f\n", average);

    /* b) Bestanden und nicht bestanden zählen */
    int passed = 0;
    int failed = 0;
    for (int i = 0; i < count; i++) {
        if (scores[i] >= 60) {
            passed++;
        } else {
            failed++;
        }
    }
    printf("Passed: %d, Failed: %d\n", passed, failed);

    /* c) Höchsten und niedrigsten Wert finden */
    int highest = scores[0];
    int lowest  = scores[0];
    for (int i = 1; i < count; i++) {
        if (scores[i] > highest) {
            highest = scores[i];
        }
        if (scores[i] < lowest) {
            lowest = scores[i];
        }
    }
    printf("Highest: %d, Lowest: %d\n", highest, lowest);
}

int aufgabe_3(){
    char username[20];
    char greeting[50];

    printf("Enter your username: ");
    if (fgets(username, sizeof(username), stdin) != NULL) {
        username[strcspn(username, "\n")] = '\0';
    }

    int len = snprintf(greeting, sizeof(greeting), "Welcome, %s!", username);
    if (len >= (int)sizeof(greeting)) {
        printf("Warning: greeting was truncated.\n");
    }

    printf("%s\n", greeting);

    /* Alphabetische Zeichen und Ziffern zählen */
    int letter_count = 0;
    int digit_count  = 0;

    for (int i = 0; username[i] != '\0'; i++) {
        if (isalpha((unsigned char)username[i])) {
           letter_count++;
        } else if (isdigit((unsigned char)username[i])) {
           digit_count++;
        }
    }

    printf("Letters: %d\n", letter_count);
    printf("Digits:  %d\n", digit_count);

}

int aufgabe_4(){

    char dict[5][20] = {0};

    for (int i = 0; i < 5; i++) {
        if (fgets(dict[i], sizeof(dict[i]), stdin) == NULL) {
            break;
        }
        dict[i][strcspn(dict[i], "\n")] = '\0';
    }
    int großbuchstabe = 0;
    int kleinbuchstabe = 0;
    bool is_upper = false;
    printf("\nEingegebene Wörter:\n");
    for(int i = 0; i < 5; i++){
        if(isupper((unsigned char)dict[i][0])){
            großbuchstabe++;
            is_upper = true;
        } else {
            kleinbuchstabe++;
            is_upper = false;
        }
        printf("[%d] \"%s\" strlen - %zu Großbuchstabe - %s \n", i, dict[i], strlen(dict[i]), is_upper? "ja" : "nein");
    }
    printf("großbuchstabe - %d; kleinbuchstabe - %d", großbuchstabe, kleinbuchstabe);
}

int main(void){
    aufgabe_4();
    return 0;
}