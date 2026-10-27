// Übung 02.4.Ü.01
// Abschlussbedingungen
//  Erledigt: Anzeigen
// Aufgabe: Daten in C speichern, anzeigen und konvertieren
// Wende dein Wissen über C-Variablen, Datentypen, Ein-/Ausgabe und Typkonvertierungen an, indem du die folgenden Aufgaben erledigst. Jeder Teil konzentriert sich auf einen anderen Aspekt der Arbeit mit Daten in C.

// a) Deklariere Variablen der folgenden Typen und weise ihnen geeignete Anfangswerte zu: einen vorzeichenbehafteten 32-Bit-Integer mit einem Typ fixer Breite, eine Gleitkommazahl mit doppelter Genauigkeit, ein einzelnes Zeichen und ein boolesches Flag. Gib alle vier Werte mit printf und den jeweils korrekten Formatangaben auf dem Terminal aus. Vergiss nicht, <stdio.h> und <stdint.h> einzubinden.

// b) Schreibe ein kurzes Programm, das den Benutzer auffordert, eine ganze Zahl und eine Dezimalzahl (double) einzugeben. Lies beide Werte mit scanf und den passenden Formatangaben ein. Gib die Werte dann zurück aus, wobei der Integer rechtsbündig in einem Feld der Breite 8 und der Double mit genau 3 Dezimalstellen angezeigt werden. Überprüfe den Rückgabewert von scanf, um zu bestätigen, dass beide Werte erfolgreich eingelesen wurden.

// c) Gegeben sind die Integer-Variablen int numerator = 22 und int denominator = 7. Berechne und gib das Ergebnis der Division auf drei Arten aus:

// Als Integer-Division (ohne Cast)
// Als Gleitkomma-Division mit einem expliziten Cast auf numerator
// Als Gleitkomma-Division durch Zuweisung des Ergebnisses an eine double-Variable und erkläre (in einem Kommentar), warum dies allein das Problem der Integer-Division nicht behebt
// d) Erkläre, was passiert, wenn der Wert 300 mit dem Ausdruck char c = (char)300; einer char-Variable zugewiesen wird. Welchen Wert enthält c und warum? Nenne den allgemeinen Begriff für diese Art der Konvertierung.

// GCC oder Clang Compiler mit C23-Unterstützung (-std=c23)
// Compiler-Flags: -Wall -Wextra
// Header <stdio.h>, <stdint.h>
// Texteditor oder IDE (z. B. VS Code mit C/C++-Erweiterung)

// Übung 02.4.Ü.02
// Abschlussbedingungen
//  Erledigt: Anzeigen
// Aufgabe: Mit Typkonvertierungen und formatierter Ausgabe arbeiten
// Wende dein Wissen über C-Datentypen, Typkonvertierungen und formatierte Ausgabe an, um eine Reihe von C-Code-Ausschnitten zu analysieren und zu korrigieren. Identifiziere für jeden Ausschnitt, was beim Ausführen des Codes passiert, erkläre warum, und schreibe die korrigierte oder verbesserte Version.

// a) Das folgende Programm versucht, den Durchschnitt zweier Integer-Werte zu berechnen und das Ergebnis mit zwei Dezimalstellen auszugeben. Kompiliere es und analysiere es gedanklich (oder führe es tatsächlich aus), erkläre dann, welche Ausgabe es erzeugt und warum das Ergebnis nicht 3.5 ist. Schreibe eine korrigierte Version, die das erwartete Ergebnis liefert.

// #include <stdio.h>

// int main(void) {
//     int a = 5;
//     int b = 2;
//     double avg = a / b;
//     printf("Average: %d\n", avg);
//     return 0;
// }
// b) Deklariere die folgenden Variablen mit den am besten geeigneten Datentypen, initialisiere sie mit den angegebenen Werten und gib jede mit der korrekten printf-Formatangabe aus. Stelle sicher, dass deine Formatangaben exakt mit den Typen übereinstimmen.

// c)    Erkläre, was eine verengende Konvertierung ist, und beschreibe die zwei spezifischen Datenverluste, die bei den folgenden zwei Zuweisungen auftreten. Gib den tatsächlich gespeicherten Wert für jeden Fall an.

// double price = 7.99;
// int   cents = (int)price;

// int offset = 300;
// char small  = (char)offset;
// d) Schreibe ein kleines C-Programm, das mit scanf eine ganze Zahl und eine Dezimalzahl vom Benutzer einliest und dann beide Werte zusammen mit ihrer Summe als double ausgibt. Überprüfe den Rückgabewert von scanf und gib eine Fehlermeldung aus, wenn die Eingabe ungültig ist.

// GCC oder Clang Compiler mit den Flags -Wall -Wextra -std=c23
// Texteditor oder VS Code mit der C/C++-Erweiterung
// Terminal zum Kompilieren und Ausführen des Programms
// Header <stdio.h>, <stdint.h>

#include <stdio.h>
#include <stdint.h>

int aufgabe_1a(){
    int32_t  population = 1'000'000;   // fixed-width 32-bit signed integer
    double   temperature = 98.6;        // double-precision float
    char     grade       = 'B';         // single character
    bool     is_active   = true;        // boolean flag

    printf("Population : %d\n",  population);
    printf("Temperature: %f\n",  temperature);
    printf("Grade      : %c\n",  grade);
    printf("Active     : %d\n",  is_active);   // bool prints as 1 (true) or 0 (false)
}

int aufgabe_1b(){
    int    whole_number;
    double decimal_number;

    printf("Enter an integer and a decimal number: ");
    int items_read = scanf("%d %lf", &whole_number, &decimal_number);

    if (items_read == 2) {
        printf("Integer : %8d\n",   whole_number);      // right-aligned, width 8
        printf("Decimal : %.3f\n",  decimal_number);    // 3 decimal places
    } else {
        printf("Error: could not read both values.\n");
    }
}

int aufgabe_1c(){
     int numerator   = 22;
    int denominator = 7;

    // Integer division: truncates fractional part
    printf("Integer division  : %d\n", numerator / denominator);   // 3

    // Floating-point division via explicit cast
    printf("Float division    : %f\n", (double)numerator / denominator); // 3.142857

    // Assigning to double DOES NOT fix the issue
    double result = numerator / denominator;
    // The division 22 / 7 is evaluated as integer division (both operands are int),
    // giving 3. Only then is 3 converted to 3.0 and stored in result.
    printf("Double variable   : %f\n", result); // 3.000000 - still wrong!

}

int aufgabe_2a(){
    int a = 5;
    int b = 2;
    double avg = (double)a / b;
    printf("Average: %lf\n", avg);
    return 0;
}

int aufgabe_2b(){
    double   temperature = 98.6;
    char     letter      = 'Z';
    long long population = 8'100'000'000LL;
    uint8_t  byte_flag   = 0b10110011;

    printf("Temperature: %f\n",   temperature);   // %f for double
    printf("Letter:      %c\n",   letter);         // %c for char
    printf("Population:  %lld\n", population);     // %lld for long long
    printf("Byte flag:   %u\n",   byte_flag);      // %u for uint8_t (unsigned)
}

//d) Schreibe ein kleines C-Programm, das mit scanf eine ganze Zahl und eine Dezimalzahl 
// vom Benutzer einliest und dann beide Werte zusammen mit ihrer Summe als double ausgibt. 
// Überprüfe den Rückgabewert von scanf und gib eine Fehlermeldung aus, wenn die Eingabe ungültig ist.

int aufgabe_2d(){
    int ganze_zahl;
    double dezimalzahl;
    printf("Enter an integer and a decimal number: ");
    scanf("%d %lf", &ganze_zahl, &dezimalzahl);
    printf("Summa = %lf\n", (double)ganze_zahl+dezimalzahl);

}

int main(void){
    aufgabe_2b();
    return 0;
}