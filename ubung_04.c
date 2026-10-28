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



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Übung 04.3.Ü.01
// Abschlussbedingungen
//  Erledigt: Anzeigen
// Aufgabe: Die switch-Anweisung und bedingte Logik anwenden
// Wende dein Wissen über switch-Anweisungen und if-else-Bedingungen an, um die folgenden Programmieraufgaben zu lösen. Schreibe für jede Aufgabe den vollständigen C-Code, der das beschriebene Verhalten erfüllt.

// a) Schreibe ein C-Programm, das eine ganze Zahl vom Benutzer einliest, die einen Wochentag repräsentiert (1 = Montag, 2 = Dienstag, …, 7 = Sonntag). Verwende eine switch-Anweisung, um den vollständigen Namen des Tages auszugeben. Falls der Benutzer einen Wert außerhalb von 1–7 eingibt, gib "Invalid day" aus. Stelle sicher, dass jeder case korrekt beendet wird, sodass kein unbeabsichtigtes Fall-Through auftritt.

// b) Erweitere das Programm aus Teil a), indem du einen zweiten switch (oder dieselbe Struktur) hinzufügst, der die Tage in Kategorien einteilt und nach dem Tagesnamen eine der folgenden Meldungen ausgibt:

// Tage 1–5: "Weekday"
// Tage 6–7: "Weekend"
// Verwende absichtliches Fall-Through (gestapelte case-Labels ohne Code dazwischen), um die Tage effizient zu gruppieren.

// c) Schreibe ein kleines Codesegment, das eine ganze Zahl als Punktzahl (0–100) einliest und eine if-else-if-Kette verwendet, um eine Buchstabennote auszugeben:

// 90 und darüber: "Grade: A"
// 80–89: "Grade: B"
// 70–79: "Grade: C"
// 60–69: "Grade: D"
// Unter 60: "Grade: F"
// Verwende nach der Ausgabe der Note den ternären Operator, um zu bestimmen und auszugeben, ob der Schüler bestanden oder nicht bestanden hat: "Result: Pass" wenn die Note 60 oder darüber liegt, andernfalls "Result: Fail".


#include <stdio.h>

//if-else if - else
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

//switch - case
int aufgabe_2(){
    int day;
    printf("Enter a number, die einen Wochentag repräsentiert (1 = Montag, 2 = Dienstag, …, 7 = Sonntag): ");
    scanf("%d", &day);

    switch (day) {
        case 1:
            printf("Montag\n");
            break;
        case 2:
            printf("Dienstag\n");
            break;
        case 3:
            printf("Mittwoch\n");
            break;
        case 4:
            printf("Thuersday\n");
            break;
        case 5:
            printf("Frieday\n");
            break;
        case 6:
            printf("Saturday\n");
            break;
        case 7:
            printf("Sunday\n");
            break;
        default:
            printf("Anderer Tag\n");
            break;
    }

    switch (day) {
    case 1: case 2: case 3: case 4: case 5:
        printf("Weekday\n");
        break;
    case 6: case 7:
        printf("Weekend\n");
        break;
    default:
        printf("Invalid day\n");
        break;
    }

    int score;
    printf("Enter score (0-100): ");
    scanf("%d", &score);

    if (score >= 90) {
        printf("Grade: A\n");
    } else if (score >= 80) {
        printf("Grade: B\n");
    } else if (score >= 70) {
        printf("Grade: C\n");
    } else if (score >= 60) {
        printf("Grade: D\n");
    } else {
        printf("Grade: F\n");
    }

    const char *result = (score >= 60) ? "Pass" : "Fail";
    printf("Result: %s\n", result);

}


int main(void){
    aufgabe_2();
}