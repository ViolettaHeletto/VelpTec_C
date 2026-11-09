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
// Übung 08.2.Ü.02
// Abschlussbedingungen
//  Erledigt: Anzeigen
// Aufgabe: Zeiger zum Verändern von Variablen und zur Rückgabe mehrerer Ergebnisse verwenden
// Wende dein Wissen über Zeiger-Grundlagen und Call-by-Reference an, um die folgenden Aufgaben zu lösen. Jeder Teil erfordert, dass du eine vollständige, kompilierbare C-Funktion oder ein kurzes Programm schreibst.

// a) Schreibe eine Funktion void clamp(int *value, int min, int max), die den Integer, auf den value zeigt, so verändert, dass er im Bereich [min, max] liegt. Wenn *value kleiner als min ist, setze ihn auf min. Wenn er größer als max ist, setze ihn auf max. Andernfalls lass ihn unverändert. Schreibe dann eine kurze main-Funktion, die clamp mit mindestens drei verschiedenen Fällen testet: einem Wert unterhalb des Minimums, einem Wert oberhalb des Maximums und einem Wert, der bereits im Bereich liegt. Gib das Ergebnis nach jedem Aufruf aus.

// b) Schreibe eine Funktion void min_max(int *arr, int size, int *out_min, int *out_max), die ein Integer-Array durchsucht und den kleinsten Wert in *out_min und den größten Wert in *out_max schreibt. Verwende eine for-Schleife, um über das Array zu iterieren. Deklariere in main ein Array {34, 7, 19, 52, 3, 91, 25}, rufe min_max auf und gib die Ergebnisse aus.

// c) Erkläre in eigenen Worten, warum die Funktionssignatur void min_max(int *arr, int size, int *out_min, int *out_max) int *out_min und int *out_max als Ausgabeparameter verwendet, anstatt den minimalen oder maximalen Wert direkt zurückzugeben. Welche Einschränkung von C-Funktionen macht diesen zeigerbasierter Ansatz notwendig?
/////////////////////////////////////////////////////////////////////////////////////////
/*Übung 08.4.Ü.01
Abschlussbedingungen
 Erledigt: Anzeigen
Aufgabe: Durch den Speicher navigieren: Zeigerarithmetik und const-Zeiger
Wende dein Wissen über Zeigerarithmetik, Array-Zugriff und const-Zeigerqualifizierer an, um eine Reihe kurzer Zeigerübungen zu analysieren und zu vervollständigen. 

Schreibe für jeden der folgenden Teile den erforderlichen C-Code oder gib die gewünschte Antwort. Du kannst deinen Code mit einem C-Compiler testen, sofern verfügbar, aber die Übungen sind so gestaltet, dass sie durch logisches Durchdenken des Codes gelöst werden können.

a) Du hast folgende Array- und Zeigerdeklarationen: 

int values[5] = {10, 20, 30, 40, 50}; 
int *p = values; 
Gib die Ausgabe jedes der folgenden printf-Aufrufe an. Erkläre kurz, warum Zeigerarithmetik um sizeof(int) Bytes statt um 1 Byte vorwärts schreitet. 

printf("%d\n", *p); 
printf("%d\n", *(p + 2)); 
printf("%d\n", p[3]); 
printf("%d\n", *(values + 4)); 
b) Schreibe eine Funktion int array_sum(const int *arr, int size), die die Summe aller Elemente im Array zurückgibt. Verwende Zeigerarithmetik (d. h. inkrementiere einen Zeiger innerhalb der Schleife) anstelle der Array-Index-Notation. Erkläre in einem Satz, warum der Parameter als const int * statt als int * deklariert wird. 

c) Identifiziere den Zeigerfehler in jedem der folgenden Code-Ausschnitte und erkläre, welche Fehlerkategorie er darstellt (dangling pointer, wild pointer oder null dereference). Beschreibe für jeden einen konkreten Fix. 


Ausschnitt 1: 

int *get_value(void) { 
    int x = 99; 
    return &x; 
} 
Ausschnitt 2: 

int *p; 
*p = 42; 
Ausschnitt 3: 

int *p = nullptr; 
printf("%d\n", *p); 
d) Erkläre den Unterschied zwischen den folgenden zwei Deklarationen. Gib für jede an: (1) ob der Zeiger selbst geändert werden kann, und (2) ob der Wert, auf den er zeigt, geändert werden kann.
const int *a;
int *const b;
*/
/////////////////////////////////////////////////////////////////////////////////////////
/*
Übung 08.4.Ü.02
Abschlussbedingungen
 Erledigt: Anzeigen
Aufgabe: Zeiger mit Funktionen und Arrays verwenden

Wende Zeigerkonzepte an, um eine Funktion zu implementieren, die ihre Argumente per Referenz verändert und ein Array über Zeigerarithmetik verarbeitet. 

Gegeben das folgende Programmskelett und die nachstehenden Anforderungen, bearbeite jede der folgenden Teilaufgaben. 

a) Implementiere eine Funktion void minmax(int *arr, int size, int *out_min, int *out_max), die: 

Einen Zeiger auf ein Integer-Array und dessen Größe entgegennimmt 

Den minimalen und maximalen Wert im Array bestimmt 

Den Minimalwert in *out_min und den Maximalwert in *out_max schreibt 

Erkläre, warum die Parameter out_min und out_max Zeigertypen (int *) sein müssen und keine einfachen int-Parameter. 

b) Implementiere eine zweite Funktion int count_positive(const int *arr, int size), die: 

Einen Zeiger auf ein konstantes Integer-Array und dessen Größe entgegennimmt 

Die Anzahl der Elemente zurückgibt, die größer als null sind 

Das Array mithilfe von Zeigerarithmetik durchläuft (d.h. verwende *(arr + i) oder inkrementiere den Zeiger direkt, NICHT den Index arr[i]) 

Erkläre, was der const-Qualifier bei arr dem Aufrufer dieser Funktion signalisiert. 

c) Schreibe eine main-Funktion, die: 

Ein Integer-Array int data[] = {3, -1, 7, 0, -5, 12, 4, -8, 2, 6} (10 Elemente) deklariert 

minmax aufruft und dabei die korrekten Adressen für die Ausgabevariablen übergibt 

count_positive aufruft und dabei das Array übergibt 

Den Minimal-, den Maximalwert und die Anzahl der positiven Zahlen ausgibt 
*/
/////////////////////////////////////////////////////////////////////////////////////////
/**/
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
void aufgabe1(){
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
}

void min_max(int *arr, int size, int *out_min, int *out_max){
    for(int i = 0; i < size; i++){
        if (arr[i] < *out_min)
        {
            *out_min = arr[i];
        }
        if (arr[i] > *out_max)
        {
            *out_max = arr[i];
        }
    }
}

void aufgabe2(){
    int arr [7]= {34, 7, 19, 52, 3, 91, 25};
    int min = arr[0];
    int max = arr[0];
    min_max(arr, 7, &min, &max);
}

void aufgabe3a(){
    int values[5] = {10, 20, 30, 40, 50};
    int *p = values;
    printf("%d\n", *p);
    printf("%d\n", *(p + 2));
    printf("%d\n", p[3]);
    printf("%d\n", *(values + 4));
}

int array_sum(const int *arr, int size){
    int total = 0;
    const int *end = arr + size;
    for (const int *p = arr; p < end; p++) {
        total += *p;
    }
    return total;
}

void minmax(int *arr, int size, int *out_min, int *out_max){
    for(int i = 0; i < size; i++){
        if (arr[i] < *out_min)
        {
            *out_min = arr[i];
        }
        if (arr[i] > *out_max)
        {
            *out_max = arr[i];
        }
    }
}

int main(void){
    aufgabe3a();
    return 0;
}