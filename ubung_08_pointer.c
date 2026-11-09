/*
int main(void) {
int x = 42;
int *p = &x;
// p enthält die Adresse von x
printf("Adresse von x: %p\n", (void *)p);   // z.B. 0x7fff5abc
printf("Wert an dieser Adresse: %d\n", *p);  // 42
*p = 100;
// durch den Zeiger schreiben
printf("x ist jetzt: %d\n", x);  // 100 - x wurde geändert!
return 0;
}*/


// Übung 08.2.Ü.01
// Abschlussbedingungen
//  Erledigt: Anzeigen
// Aufgabe: Arbeiten mit Zeigern und Call-by-Reference

// Wende dein Wissen über Zeiger an, um Funktionen zu implementieren, die Variablen im Gültigkeitsbereich des Aufrufers tatsächlich verändern. In C wird jedes Argument beim Übergeben an eine Funktion kopiert (Call-by-Value). Wenn du also möchtest, dass eine Funktion eine Variable im aufrufenden Code verändert, musst du einen Zeiger auf diese Variable übergeben.

// Implementiere die folgenden drei Funktionen sowie eine main-Funktion, die jede von ihnen demonstriert:

// a) Schreibe eine Funktion reset(int *value), die den Integer an der angegebenen Adresse auf 0 setzt. Rufe sie mit einer Variablen auf, die einen Wert ungleich null hat, und gib die Variable vor und nach dem Aufruf aus.

// b) Schreibe eine Funktion clamp(int *value, int min, int max), die den Integer an der angegebenen Adresse so verändert, dass er im Bereich [min, max] liegt. Wenn der Wert kleiner als min ist, setze ihn auf min; wenn er größer als max ist, setze ihn auf max; andernfalls lass ihn unverändert. Rufe die Funktion mit mindestens zwei Testfällen auf: einem, bei dem der Wert außerhalb des Bereichs liegt, und einem, bei dem er bereits innerhalb des Bereichs liegt. Gib das Ergebnis nach jedem Aufruf aus.

// c) Schreibe eine Funktion split(int source, int *out_high, int *out_low), die einen einzelnen Integer entgegennimmt und seine obere und untere Hälfte über Zeiger in zwei separate Ausgabevariablen schreibt. Die obere Hälfte ist source / 2 (Ganzzahldivision) und die untere Hälfte ist source % 2 (der Rest). Demonstriere die Funktion, indem du sie aufrufst und beide Ausgabewerte ausgibst.
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>

void reset(int *value){
    *value = 0;
}

void clamp(int *value, int min, int max){
    if(*value < min){
        *value = min;
    } else if(*value > max){
        *value = max;
    }

}

void split(int source, int *out_high, int *out_low){
    *out_high = source / 2;
    *out_low = source % 2;
}

int main(void){
    int a = 20;
    printf("%d\n", a);
    reset(&a);
    printf("%d\n", a);

    int more = 50;
    int less = 1;
    int middle = 15;
    clamp(&more, 5, 45);
    clamp(&less, 5, 45);
    clamp(&middle, 5, 45);
    printf("%d %d %d\n", more, middle, less);

    int high, low;
    split(25, &high, &low);
    printf("%d %d\n", high, low);
    return 0;
}