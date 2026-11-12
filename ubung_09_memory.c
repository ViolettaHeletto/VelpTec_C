/*
Übung 09.2.Ü.01
Abschlussbedingungen
 Erledigt: Anzeigen
Aufgabe: Dynamischen Speicher allokieren und sicher freigeben

Wende die vier Heap-Allokationsfunktionen an, um eine kleine dynamisch allokierte Integer-Sammlung aufzubauen und zu verwalten. In jeder Teilaufgabe verwendest du eine andere Allokationsfunktion und erledigst die erforderliche Aufräumarbeit korrekt. 

Folgendes Setup ist am Anfang deines Programms gegeben: 

#include <stdio.h> 
#include <stdlib.h> 
 
int main(void) { 
    // dein Code kommt hier hin 
    return 0; 
} 



a) Verwende malloc, um auf dem Heap genau Platz für 5 int-Werte zu allokieren. Überprüfe, ob die Allokation erfolgreich war; schlägt sie fehl, gib eine Fehlermeldung auf stderr aus und beende das Programm mit Rückgabecode 1. Weise dann den fünf Elementen die Werte 10, 20, 30, 40, 50 über die Array-Index-Notation zu und gib alle fünf Werte mit einer Schleife aus. Gib abschließend den Speicher frei und setze den Zeiger auf nullptr. 

b) Verwende calloc, um auf dem Heap Platz für 8 int-Werte zu allokieren. Gib alle 8 Werte aus, ohne ein Element manuell zu initialisieren. Erkläre in einem Kommentar in deinem Code, warum jedes Element bereits den Wert 0 hat. Gib den Speicher anschließend frei und setze den Zeiger auf nullptr. 

c) Beginne mit einem per malloc allokierten Block für 3 int-Werte. Weise den Elementen 1, 2, 3 zu. Verwende dann realloc, um den Block auf 6 int-Werte zu vergrößern. Nutze einen temporären Zeiger für den realloc-Aufruf und behandle einen möglichen Fehler korrekt (ohne den ursprünglichen Block zu verlieren). Weise den neuen Elementen 4, 5, 6 zu, gib alle 6 Werte aus und gib den Speicher anschließend frei. 

d) Der folgende Code enthält drei verschiedene Speicherfehler. Benenne jeden Fehler, beschreibe, was zur Laufzeit schiefgeht, und gib an, wie du ihn beheben würdest.

int *p = malloc(sizeof(int) * 3); 
p[0] = 1; 
p[3] = 9;          // Zeile A 
free(p); 
printf("%d\n", *p); // Zeile B 
free(p);            // Zeile C 
*/
/////////////////////////////////////////////////////////////////////////////////////////
/*
Übung 09.2.Ü.02
Abschlussbedingungen
 Erledigt: Anzeigen
Aufgabe: Heap-Speicher allokieren, vergrößern und sicher freigeben

Wende dein Wissen über C’s dynamische Speicherfunktionen an, um ein kleines Programm zu implementieren, das einen dynamisch allokierten Integer-Puffer aufbaut, dessen Größe ändert und ihn korrekt aufräumt. 

Bearbeite die folgenden Teilaufgaben. Schreibe den gesamten Code in einer einzigen .c-Datei und kompiliere mit gcc -Wall -Wextra -std=c23. 

a) Allokiere mit malloc einen Heap-Puffer für genau 5 int-Werte. Überprüfe den Rückgabewert und gib mit fprintf eine Fehlermeldung auf stderr aus, falls die Allokation fehlschlägt, und gib dann 1 aus main zurück. Nach einer erfolgreichen Allokation initialisiere alle 5 Elemente mit den Werten 10, 20, 30, 40, 50 über direkten Array-Index-Zugriff. 

b) Vergrößere den Puffer mit realloc auf 10 int-Werte. Verwende einen temporären Zeiger, um den Rückgabewert aufzunehmen. Schlägt realloc fehl, gib den ursprünglichen Puffer frei und gib 1 zurück. Nach einer erfolgreichen Vergrößerung setze die Elemente an den Indizes 5 bis 9 auf die Werte 60, 70, 80, 90, 100. 

c) Gib alle 10 Werte in einer einzigen Zeile, durch Leerzeichen getrennt, mithilfe einer for-Schleife aus. 

d) Gib den Puffer korrekt frei. Setze den Zeiger nach dem Aufruf von free auf nullptr, um einen versehentlichen Use-after-free zu verhindern. Erkläre dann in einem kurzen Kommentar in deinem Code, warum das Zuweisen von nullptr nach free als gute Praxis gilt.
*/
/////////////////////////////////////////////////////////////////////////////////////////
/*

Übung 09.3.Ü.01
Abschlussbedingungen
 Erledigt: Anzeigen
Aufgabe: Ein dynamisches Array in C aufbauen und verwalten

Beschreibe, wie ein dynamisches Array in C mit manueller Speicherverwaltung funktioniert. Erkläre die Kernkonzepte hinter seinem Aufbau und wie das size/capacity-Muster, realloc und die Ownership-Disziplin zusammenwirken, um sicheren, wachsenden Speicher zu schaffen. 

a) Erkläre den Unterschied zwischen size und capacity in einer dynamischen Array-Implementierung. Warum werden zwei separate Werte statt nur eines benötigt? 

b) Beschreibe Schritt für Schritt, was passiert, wenn eine push-Operation auf einem bereits vollen dynamischen Array aufgerufen wird. Beschreibe dabei: welche Werte geprüft werden, welche Allokationsfunktion verwendet wird, wie ein Fehler sicher behandelt wird und wie die Felder danach aktualisiert werden. 

c) Vergleiche die zwei Ansätze zur Allokation eines 2D-dynamischen Arrays in C: den Array-of-Pointers-Ansatz und den zusammenhängenden Block-Ansatz. Gib für jeden Ansatz die Anzahl der erforderlichen Allokationsaufrufe, die Anzahl der erforderlichen free-Aufrufe sowie einen Vor- und einen Nachteil an. 

d) Erkläre die Ownership-Disziplin für dynamischen Speicher. Was bedeutet es, dass ein Stück Code eine Allokation “besitzt”, und warum ist das Dokumentieren von Ownership in C-Programmen wichtig?

*/
/////////////////////////////////////////////////////////////////////////////////////////
/*
Transferaufgabe 09.3.A.01
Abschlussbedingungen
 Erledigt: Anzeigen
Aufgabe: Einen dynamischen Worthäufigkeitszähler bauen
Deine Aufgabe ist es, einen dynamischen Wort-Häufigkeitszähler in C zu entwerfen und umzusetzen — ein Programm, das Wörter vom Benutzer einliest, mitzählt, wie oft jedes einzelne Wort vorkommt, und die Ergebnisse ausgibt.
Die Umsetzung muss parallele dynamische Heap-Arrays verwenden, um die Wörter und ihre Zählerstände zu speichern. Das bedeutet zwei getrennt allokierte Arrays, die immer gleich lang sind und immer gemeinsam wachsen: Ein Array enthält die Wörter, das andere die zugehörigen Zählerstände. Du darfst weder struct noch typedef struct verwenden. Die gesamte Verwaltung liegt in einfachen lokalen Variablen.
Arbeite die folgenden Teilaufgaben der Reihe nach durch. Jede Teilaufgabe baut auf den vorherigen auf.
a) Entwirf das Datenmodell mit parallelen Arrays. Beschreibe (in Worten und/oder Code) ein Datenmodell mit zwei parallelen Heap-Arrays — eines für die Wörter und eines für die Zählerstände — plus einfache lokale Variablen für size und capacity. Gib genau an, welche Zeigertypen du für jedes Array verwenden würdest, welche Allokationsfunktion (malloc, calloc oder realloc) du für die erste Erzeugung jedes Arrays nutzen würdest und warum. Erkläre, wie Index i im Wörter-Array dem Index i im Zähler-Array entspricht.
b) Implementiere eine Funktion zum Hinzufügen oder Zählen eines Worts. Schreibe eine C-Funktion mit der folgenden Signatur (oder einer gleichwertigen):
int add_or_count(char ***words, int **counts, size_t *size, size_t *capacity,
                 const char *word);
Die Funktion muss: das bestehende Wörter-Array mit strcmp durchsuchen, um zu prüfen, ob word bereits gespeichert ist; falls gefunden, counts[i] für diesen Index erhöhen; falls nicht gefunden, einen neuen Eintrag mit Zählerstand 1 hinzufügen und dabei beide Arrays dynamisch vergrößern, wenn *size == *capacity (verwende realloc mit einer Verdopplungsstrategie und leite immer über einen temporären Zeiger). Setze beim Kopieren des Worts sichere String-Funktionen ein (strncpy/snprintf oder gleichwertig). Gib bei Erfolg 0 zurück und -1 bei einem Allokationsfehler.
c) Implementiere eine main-Funktion mit Eingabeschleife. Schreibe eine main-Funktion, die beide Arrays auf nullptr und size/capacity auf 0 initialisiert, dann nacheinander Wörter vom Benutzer einliest (mit fgets + strcspn, um den Zeilenumbruch zu entfernen), bis der Benutzer eine leere Zeile oder das Wort "quit" eingibt. Nach der gesamten Eingabe gibst du jedes einzelne Wort zusammen mit seinem Zählerstand im Format "word": N aus. Anschließend gibst du den gesamten allokierten Speicher frei — einschließlich jedes einzeln allokierten Wort-Strings —, bevor das Programm beendet wird.
d) Analysiere die Speicherverwaltung. Identifiziere jede Heap-Allokation in deiner Umsetzung und ordne jedem malloc-/calloc-/realloc-Aufruf den passenden free-Aufruf zu. Speziell für das words-Array gibt es zwei Allokationsebenen: das Array der Zeiger selbst und jeden einzelnen Wort-String. Erkläre, was schiefgeht (Speicherleck, Double Free, Use-after-free oder Pufferüberlauf), wenn jeweils ein free weggelassen oder zweimal aufgerufen wird. Nenne, welche Zeiger-Disziplinregeln (nach free auf nullptr setzen, bei realloc einen temporären Zeiger verwenden, Rückgabewert vor der Nutzung prüfen) du wo angewendet hast.
e) Bewerte und vergleiche zwei Designs zur Wortspeicherung. Die Wort-Strings lassen sich auf zwei Arten speichern: (1) als einzeln mit malloc angelegte Strings, auf die char **words zeigt (jedes Wort bekommt seine eigene Heap-Allokation von genau strlen(word) + 1 Bytes), oder (2) als zusammenhängender Block fester Puffergrößen, der als ein einziges realloc-Array allokiert wird, wobei Wort i bei Byte i * MAX_WORD_LEN beginnt und über Zeigerarithmetik angesprochen wird. Vergleiche beide Ansätze: Welche Auswirkungen haben sie auf den Speicher, wie hoch ist das Risiko von Pufferüberläufen, und wie aufwendig ist jeweils das Aufräumen? Welchen Ansatz würdest du für ein Produktivprogramm wählen, das Wörter unbekannter maximaler Länge verarbeiten muss, und warum?
*/
/////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

int add_or_count(char ***words, int **counts, size_t *size, size_t *capacity,
                 const char *word){
    

}

int transferaufgabe(){

}

int main(void){
    transferaufgabe();
    return 0;
}


int aufgabe1(){
    int *nums = malloc(sizeof(int)*5);
    if(nums == nullptr){
        fprintf(stderr, "Allocation failed\n");
        return EXIT_FAILURE;
    }
    nums[0] = 10;
    nums[1] = 20;
    nums[2] = 30;
    nums[3] = 40;
    nums[4] = 50;

    for (int i = 0; i < 5; i++) {
        printf("%d\n", nums[i]);
    }

    free(nums);
    nums = nullptr;

    int *nums0 = calloc(8, sizeof(int));
    if(nums0 == nullptr){
        fprintf(stderr, "Allocation failed\n");
        return EXIT_FAILURE;
    }
    for (int i = 0; i < 8; i++) {
        printf("%d\n", nums0[i]);
    }

    free(nums0);
    nums0 = nullptr;

    int *nums1 = malloc(sizeof(int)*3);
    if(nums1 == nullptr){
        fprintf(stderr, "Allocation failed\n");
        return EXIT_FAILURE;
    }
    nums1[0] = 1;
    nums1[1] = 2;
    nums1[2] = 3;

    int *tmp = realloc(nums1, 6 * sizeof *nums1);
    if (!tmp) {
        fprintf(stderr, "Reallocation failed\n");
        free(nums1);            // старый блок ещё жив — освобождаем
        return EXIT_FAILURE;
    }
    nums1 = tmp;   // только теперь можно перезаписать указатель
    nums1[3] = 4;
    nums1[4] = 5;
    nums1[5] = 6;

    for (int i = 0; i < 6; i++) {
        printf("%d\n", nums1[i]);
    }

    free(nums1);
    nums1 = nullptr;
}

int aufgabe2(){
     int *buf = malloc(sizeof(int) * 5); 
    if (buf == nullptr) { 
        fprintf(stderr, "Allocation failed\n"); 
        return 1; 
    } 
 
    buf[0] = 10; 
    buf[1] = 20; 
    buf[2] = 30; 
    buf[3] = 40; 
    buf[4] = 50; 
    int *tmp = realloc(buf, sizeof(int) * 10); 
    if (tmp == nullptr) { 
        free(buf);   // original block is still valid, clean it up 
        return 1; 
    } 
    buf = tmp;       // only update buf after confirming success 

    buf[5] = 60; 
    buf[6] = 70; 
    buf[7] = 80; 
    buf[8] = 90; 
    buf[9] = 100; 
    for (int i = 0; i < 10; i++) { 
        printf("%d ", buf[i]); 
    } 
    printf("\n"); 
    free(buf);
    buf = nullptr;
}
