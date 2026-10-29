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

/////////////////////////////////////////////////////////////////////////////////////////
// Übung 05.2.Ü.02
// Abschlussbedingungen
//  Erledigt: Anzeigen
// Aufgabe: Schleifen mit Bedingungen schreiben und analysieren
// Wende dein Wissen über C-Schleifen und Bedingungsanweisungen an, um die folgenden Aufgaben zu lösen. Jede Teilaufgabe erfordert, dass du Schleifenverhalten mit while, do-while und for-Schleifen kombiniert mit den Operatoren und Datentypen, die du kennengelernt hast, nachvollziehst, schreibst oder vorhersagst.

// a) Ausgabe nachvollziehen: Bestimme, was das folgende Programm Schritt für Schritt ausgibt. Schreibe jede Ausgabezeile auf und erkläre, was in jeder Iteration passiert.

// #include <stdio.h>

// int main(void) {
//     int total = 0;
//     int i = 1;
//     while (i <= 4) {
//         if (i % 2 == 0) {
//             total += i * 2;
//         } else {
//             total += i;
//         }
//         printf("i=%d total=%d\n", i, total);
//         i++;
//     }
//     return 0;
// }
// b) Schleife mit do-while schreiben: Schreibe ein vollständiges C-Programm, das eine do-while-Schleife verwendet, um eine ganze Zahl vom Benutzer einzulesen. Die Schleife muss so lange erneut fragen, bis der Benutzer einen Wert strikt zwischen 1 und 100 (exklusiv) eingibt. Sobald ein gültiger Wert eingegeben wurde, gib aus: Valid input: <value>.

// c) Verschachtelte for-Schleife schreiben: Schreibe ein vollständiges C-Programm, das verschachtelte for-Schleifen verwendet, um das folgende Zahlenmuster im Terminal auszugeben. Die äußere Schleife steuert die Zeilen (1 bis 4) und die innere Schleife gibt die Spaltenwerte aus. Jede Zeilennummer wird so oft wiederholt, wie die Zeilennummer selbst angibt.

// 1
// 2 2
// 3 3 3
// 4 4 4 4
// d) Einen Fehler finden und beheben: Das folgende Programm soll die Summe aller ganzen Zahlen von 1 bis n berechnen, wobei n vom Benutzer eingegeben wird. Es enthält einen Fehler. Identifiziere den Fehler und schreibe die korrigierte Version.

// #include <stdio.h>

// int main(void) {
//     int n;
//     printf("Enter n: ");
//     scanf("%d", &n);

//     int sum = 0;
//     for (int i = 1; i <= n; i++) {
//         sum = i;
//     }
//     printf("Sum from 1 to %d = %d\n", n, sum);
//     return 0;
// }
/////////////////////////////////////////////////////////////////////////////////////////

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

int aufgabe_2b(){
    int value;
    do{
        scanf("%d", &value);
        printf("Valid input: %d", value);
    }while( value >= 1 && value <= 100);
}

int aufgabe_2c(){
    for (int row = 1; row <= 4; row++) {
        for (int col = row; col >= 1; col--) {
            printf("%d ", row);
        }
        printf("\n");
    }
}

int aufgabe_2d(){
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
    }
    printf("Sum from 1 to %d = %d\n", n, sum);
}


int main(void){
    aufgabe_2d();
    return 0;
}