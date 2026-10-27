// Übung 03.2.Ü.01
// Abschlussbedingungen
//  Erledigt: Anzeigen
// Aufgabe: C-Operatoren und Ausdrücke verstehen und anwenden
// Sage die Ausgabe vorher, erkläre sie und korrigiere das Verhalten von C-Ausdrücken mit arithmetischen Operatoren, Inkrement-/Dekrement-Operatoren und Operatorpriorität.

// Führe für jeden der folgenden Code-Ausschnitte (a bis e) die drei Schritte aus:

// Gib an, was die Ausgabe sein wird (oder beschreibe, was passiert, wenn es keine gültige Ausgabe gibt)
// Erkläre, warum dieses Ergebnis eintritt, und beziehe dich dabei auf die relevanten Operatorregeln
// Falls der Ausschnitt einen Bug oder undefiniertes Verhalten enthält, schreibe eine korrigierte Version

// Ausschnitt a)

// #include <stdio.h>

// int main(void) {
//     int a = 7, b = 2;
//     double result = (double)a / b;
//     printf("%.2f\n", result);
//     return 0;
// }

//Ausschnitt b)

// #include <stdio.h>

// int main(void) {
//     int x = 4;
//     int y = x++;
//     int z = ++x;
//     printf("x=%d y=%d z=%d\n", x, y, z);
//     return 0;
// }

// //Ausschnitt c)

// #include <stdio.h>

// int main(void) {
//     int score = 100;
//     score += 15;
//     score *= 2;
//     score %= 7;
//     printf("%d\n", score);
//     return 0;
// }

// //Ausschnitt d)

// #include <stdio.h>

// int main(void) {
//     int n = 5;
//     if (n = 0) {
//         printf("zero\n");
//     } else {
//         printf("not zero\n");
//     }
//     return 0;
// }

// //Ausschnitt e)

#include <stdio.h>

int main(void) {
    int p = 3, q = 8;
    int result = 2 + p * q - 4 / 2;
    printf("%d\n", result);
    return 0;
}
