// Teilprüfung 1
// Abschlussbedingungen
// Zu erledigen: Abgabe einreichen Zu erledigen: Eine Bewertung erhalten
// K4.0021_4.0_05.2.A.01

// Aufgabe
// Analysiere das folgende C-Programm. Es soll eine Reihe von ganzzahligen Noten vom Benutzer einlesen, zählen, wie viele Noten in jede Kategorie fallen (sehr gut, gut, bestanden, nicht bestanden), und abschließend die Ergebnisse ausgeben. Das Programm enthält mehrere Probleme, die eine korrekte Ausführung verhindern. 

// #include <stdio.h> 
 
// int main(void) { 
//     int excellent = 0, good = 0, pass = 0, fail = 0; 
//     int grade; 
//     int count = 0; 
//     constexpr int MAX_GRADES = 5; 
 
//     printf("Enter %d grades (0-100):\n", MAX_GRADES); 
 
//     int i = 1; 
//     while (i <= MAX_GRADES) { 
//         printf("Grade %d: ", i); 
//         scanf("%d", grade); 
 
//         if (grade >= 90) { 
//             excellent++; 
//         } else if (grade >= 75) { 
//             good++; 
//         } else if (grade >= 60) { 
//             pass++; 
//         } else if (grade < 0 || grade > 100) 
//             printf("Invalid grade, skipping.\n"); 
//         else { 
//             fail++; 
//         } 
 
//         count++; 
//         i++; 
//     } 
 
//     printf("\nResults after %d grades:\n", count); 
//     printf("Excellent (90-100): %d\n", excellent); 
//     printf("Good (75-89):       %d\n", good); 
//     printf("Pass (60-74):       %d\n", pass); 
//     printf("Fail (0-59):        %d\n", fail); 
 
//     double avg = count / MAX_GRADES; 
//     printf("Average entries per category: %.1f\n", avg); 
 
//     return 0; 
// } 

// a) Identifiziere und erkläre alle Fehler und logischen Probleme im Programm. Gib für jeden gefundenen Fehler genau an, wo er im Code auftritt, was das Problem ist und welche Konsequenz er zur Laufzeit oder logisch hat. 

// b) Schreibe eine korrigierte Version des Programms, die alle in Teil a) identifizierten Probleme behebt. Deine korrigierte Version muss mit gcc -Wall -Wextra -std=c23 fehlerfrei kompilieren und eine korrekte Ausgabe erzeugen. 

// c) Das Programm verwendet aktuell eine while-Schleife. Schreibe nur den Schleifenabschnitt (von der Initialisierung von i bis einschließlich der schließenden Klammer der Schleife) mit einer for-Schleife um und erkläre kurz, warum eine for-Schleife hier besser geeignet ist. 

#include <stdio.h>

int main(void) {
    int excellent = 0, good = 0, pass = 0, fail = 0;
    int grade;
    int count = 0;
    int kategorien = 4;
    constexpr int MAX_GRADES = 4;

    printf("Enter %d grades (0-100):\n", MAX_GRADES);

    //Die for-Schleife ist hier besser geeignet, weil es sich um eine Zählschleife mit fester,
    // im Voraus bekannter Anzahl von Durchläufen handelt. Sie fasst Initialisierung,
    // Abbruchbedingung und Inkrement kompakt im Schleifenkopf zusammen, wodurch
    //  der Code lesbarer und weniger fehleranfällig ist als die while-Variante mit manuellem i++ am Rumpfende.
    for (int i = 0; i <= MAX_GRADES; i++) {
        printf("Grade %d: ", i);
        //scanf erwartet für %d einen Zeiger auf int
        scanf("%d", &grade);
        //Die Prüfung auf ungültige Werte (grade < 0 || grade > 100) steht nach den Bereichsprüfungen
        if (grade < 0 || grade > 100){
            printf("Invalid grade, skipping.\n");
        } else if (grade >= 90) {
            excellent++;
            count++; //count wird bei jedem Schleifendurchlauf erhöht, auch wenn die Note als ungültig verworfen wurde
        } else if (grade >= 75) {
            good++;
            count++;
        } else if (grade >= 60) {
            pass++;
            count++;
        } else {
            fail++;
            count++;
        }
    }

    printf("\nResults after %d grades:\n", count);
    printf("Excellent (90-100): %d\n", excellent);
    printf("Good (75-89):       %d\n", good);
    printf("Pass (60-74):       %d\n", pass);
    printf("Fail (0-59):        %d\n", fail);

    double avg = (double) count / kategorien; //count und MAX_GRADES sind beide int, also wird eine Ganzzahldivision durchgeführt
                                              //die Kategorien sind vier
    printf("Average entries per category: %.1f\n", avg);

    return 0;
}
