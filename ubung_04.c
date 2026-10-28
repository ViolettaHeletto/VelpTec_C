// Übung 04.2.Ü.01
// Abschlussbedingungen
//  Erledigt: Anzeigen
// Aufgabe: Bedingungen und if-else-if-Ketten anwenden
// Entwickle ein C-Programm, das einen ganzzahligen Wert vom Benutzer einliest und ihn anhand einer Reihe von Bedingungen klassifiziert. Das Programm muss eine if-else-if-Kette verwenden, um die korrekte Klassifizierung gemäß den folgenden Regeln zu ermitteln und auszugeben.

// Aufgabe:

// Schreibe ein vollständiges C-Programm, das:

// a) Eine einzelne ganze Zahl vom Benutzer mit scanf einliest. Speichere den Wert in einer Variable vom Typ int. 
//Gib vor dem Einlesen eine kurze Aufforderung aus, zum Beispiel: "Enter a number: ".

// b) Eine if-else-if-Kette (mit passenden geschweiften Klammern bei jedem Zweig) verwendet, 
//um die Zahl nach folgenden Regeln zu klassifizieren und die entsprechende Meldung auszugeben:
// c) Nach der Klassifizierungsmeldung eine zweite Zeile ausgibt, die anzeigt, ob die Zahl gerade oder ungerade ist. Verwende den Modulo-Operator % und eine if-else-Anweisung für diese Prüfung. Die Ausgabe soll entweder "Even" oder "Odd" lauten.

// Anforderungen:

// Verwende ausschließlich int als Datentyp für die Zahl.
// Umschließe die Körper von if, else if und else immer mit geschweiften Klammern {}.
// Die Reihenfolge der Bedingungen in der if-else-if-Kette muss der im Kurs erklärten logischen Struktur folgen — platziere die spezifischsten Bedingungen so, dass kein Fall versehentlich übersprungen wird.
// Prüfe den Rückgabewert von scanf und gib "Input error" aus, falls er nicht gleich 1 ist; kehre dann mit return 1 aus main zurück.

#include <stdio.h>

int aufgabe_1(){
    int ganze_zahl;
    printf("Enter a number: ");
    scanf("%d", &ganze_zahl);

    if (ganze_zahl < 0) {
        printf("Negatgiv");
    } else if (ganze_zahl == 0) {
        printf("Ist Null");
    } else if (ganze_zahl > 0 && ganze_zahl < 10) {
        printf("Single digit positive");
    } else if (ganze_zahl >= 10  && ganze_zahl < 100) {
        printf("Two digit positive");
    } else if (ganze_zahl >= 100) {
        printf("Large positive");
    }
    printf("\n");

    if(ganze_zahl%2 == 0){
        printf("Even");
    } else {
        printf("Odd");
    }
}

int main(void){
    aufgabe_1();
}