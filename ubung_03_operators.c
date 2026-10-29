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

// #include <stdio.h>

// int main(void) {
//     int p = 3, q = 8;
//     int result = 2 + p * q - 4 / 2;
//     printf("%d\n", result);
//     return 0;
// }


#include <stdio.h>

// Übung 03.2.Ü.02
// Abschlussbedingungen
//  Erledigt: Anzeigen
// Aufgabe: Operatoren und Ausdrücke in C anwenden
// Wende C’s Operatorensatz an, um Ergebnisse für eine Reihe von praktischen Ausdrücken zu berechnen und anzuzeigen. Schreibe für jeden der folgenden Teile ein kurzes C-Programm (oder eine einzelne main-Funktion mit mehreren printf-Aufrufen), das die erforderlichen Werte berechnet und auf dem Terminal ausgibt. Kompiliere deine Programme mit gcc -Wall -Wextra -std=c23 -o task task.c und überprüfe, dass die Ausgabe den Erwartungen entspricht.

// a) Deklariere zwei int-Variablen a = 17 und b = 5. Berechne und gib die Ergebnisse aller 
// fünf arithmetischen Operatoren (+, -, *, /, %) angewendet auf a und b aus. Berechne für das 
// Divisionsergebnis auch eine zweite Version mit einem Cast und gib sie aus, sodass du ein Gleitkommaergebnis erhältst. 
// Beschrifte jede Zeile klar mit printf.

int aufgabe_a(){
    int a = 17;
    int b = 5;
    bool f = false;
    printf("a + b = %d\n",  a + b);   // 22
    printf("a - b = %d\n",  a - b);   // 12
    printf("a * b = %d\n",  a * b);   // 85
    printf("a / b = %d\n",  a / b);   // 3  (integer division, truncates)
    printf("a %% b = %d\n", a % b);   // 2  (remainder: 17 = 3*5 + 2)

    // Float division: cast one operand to double before dividing
    printf("a / b (float) = %.4f\n", (double)a / b); // 3.4000
}

// b) Deklariere int score = 80. Wende die folgende Abfolge von kombinierten 
//Zuweisungsoperationen der Reihe nach an und gib den Wert von score nach jedem Schritt aus:

// 15 addieren
// Mit 2 multiplizieren
// 30 subtrahieren
// Durch 3 dividieren (Integer-Division)
// Modulo 7 anwenden

int aufgabe_b(){
    int score = 80;
    score += 15;  printf("After += 15: %d\n", score);  // 95
    score *= 2;   printf("After *= 2:  %d\n", score);  // 190
    score -= 30;  printf("After -= 30: %d\n", score);  // 160
    score /= 3;   printf("After /= 3:  %d\n", score);  // 53 (integer division)
    score %= 7;   printf("After %%= 7:  %d\n", score); // 4  (53 = 7*7 + 4)
}

// c) Deklariere int x = 4. Verwende die Präfix- und Postfix-Inkrement-Operatoren in zwei separaten Ausdrücken und gib die Ergebnisse aus. Konkret:

// Gib den Wert von ++x (Präfix) aus, dann gib danach x aus
// Setze x wieder auf 4 zurück, dann gib den Wert von x++ (Postfix) aus, dann gib danach x aus
// Erkläre in einem Kommentar im Code, warum sich die beiden ausgegebenen Werte unterscheiden.

int aufgabe_c(){
    int x = 4;
    int y = x++;
    int z = ++x;
    printf("x=%d y=%d z=%d\n", x, y, z);
    return 0;
}
// d) Verwende den ternären Operator, um eine von zwei Meldungen zu bestimmen und auszugeben. Deklariere int temperature = 28. Wenn die Temperatur größer als 25 ist, gib "It's warm." aus, andernfalls "It's cool.". Schreibe die gesamte Entscheidung als einzelne printf-Anweisung mit dem ternären Operator.
int aufgabe_d(){
    int temperature = 28;

    printf("%s\n", (temperature > 25) ? "It's warm." : "It's cool.");

    return 0;
}

int main(void){
    aufgabe_d();
    return 0;
}