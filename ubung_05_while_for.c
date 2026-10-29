// Übung 05.2.Ü.01
// Abschlussbedingungen
//  Erledigt: Anzeigen
// Aufgabe: for-Schleifen und verschachtelte Schleifen schreiben und nachverfolgen
// Wende dein Wissen über for-Schleifen und verschachtelte Schleifen in C an, um die folgenden Aufgaben zu bearbeiten.

// a) Schreibe eine for-Schleife, die alle geraden Zahlen von 2 bis 20 (einschließlich) ausgibt, jede in einer eigenen Zeile. Verwende den zusammengesetzten Zuweisungsoperator += im Aktualisierungsschritt, sodass die Schleife in 2er-Schritten statt in 1er-Schritten läuft.

// b) Schreibe eine for-Schleife, die die Summe aller ganzen Zahlen von 1 bis 100 (einschließlich) berechnet und das Ergebnis in einer Variable namens total speichert. Gib das Ergebnis nach Ende der Schleife mit einer beschreibenden Meldung aus, zum Beispiel: Sum from 1 to 100 = 5050.

// c) Der folgende Code mit verschachtelten Schleifen enthält einen Off-by-One-Fehler. Identifiziere den Fehler, erkläre, was er verursacht, und schreibe die korrigierte Version.

// for (int row = 1; row <= 3; row++) {
//     for (int col = 0; col <= 3; col++) {
//         printf("* ");
//     }
//     printf("\n");
// }
// Die beabsichtigte Ausgabe ist ein 3×3-Raster aus Sternchen:

// * * *
// * * *
// * * *
// d) Schreibe eine verschachtelte for-Schleife, die die folgende Multiplikationstabelle für die Faktoren 1 bis 4 ausgibt. Jeder Wert soll in einem Feld von 4 Zeichen rechtsbündig ausgerichtet sein (verwende %4d in printf).

//    1   2   3   4
//    2   4   6   8
//    3   6   9  12
//    4   8  12  16

#include <stdio.h>

int aufgabe_1a(){
    for(int i = 2; i <= 20; i+=2){
        printf("%d\n", i);
    }
}

int aufgabe_1b(){
    int total = 0;
    for(int i = 1; i <= 100; i++){
        total += i;
    }
    printf("Sum from 1 to 100 = %d\n", total);
}

int aufgabe_1c(){
    for (int row = 1; row <= 3; row++) {
        for (int col = 1; col <= 3; col++) {
            printf("* ");
        }
        printf("\n");
    }
}

int aufgabe_1d(){
    for (int row = 1; row <= 4; row++) {
        for (int col = 1; col <= 4; col++) {
            printf("  %d", row*col);
        }
        printf("\n");
    }
}




int main(void){
    aufgabe_1d();
    return 0;
}