// Case Study 05.3.C.01
// Abschlussbedingungen
//  Erledigt: Anzeigen
// Aufgabe: Ein Zahlenanalyse-Tool mit Schleifen und Bedingungen erstellen
// Du arbeitest als Junior-C-Entwickler bei einer kleinen Software-Beratungsfirma. Ein Kunde benötigt ein einfaches Kommandozeilen-Tool, das eine Reihe von ganzen Zahlen vom Benutzer einliest und eine statistische Zusammenfassung ausgibt. Dein Teamleiter übergibt dir die Spezifikation und bittet dich, sie in C zu implementieren und dabei alle bisher erlernten Kontrollfluss- und Datenmanipulationskenntnisse anzuwenden.

// Das Tool soll:

// Den Benutzer auffordern, ganze Zahlen einzeln einzugeben (die Eingabe von 0 beendet die Eingabe)
// Zählen, wie viele Zahlen eingegeben wurden (ohne den Sentinel-Wert 0)
// Die Summe berechnen und den Minimum- und Maximalwert ermitteln
// Zählen, wie viele der eingegebenen Zahlen gerade und wie viele ungerade sind
// Am Ende eine formatierte Zusammenfassung ausgeben
// Deine Aufgaben:

// a) Schreibe ein vollständiges C-Programm, das das oben beschriebene Tool implementiert. Verwende eine do-while-Schleife für die erste Eingabeaufforderung und eine while-Schleife (oder for-Schleife) für die wiederholte Eingabe. Verwende break oder das Sentinel-Muster, um bei der Eingabe von 0 zu stoppen. Verwende if- und else-Anweisungen, um Minimum, Maximum sowie die Anzahl gerader und ungerader Zahlen zu verfolgen.

// b) Der Kunde fordert später eine Änderung: Vor der Ausgabe der Zusammenfassung soll das Programm den Durchschnitt (Summe / Anzahl) mithilfe eines switch-ähnlichen Ansatzes klassifizieren. Klassifiziere den Durchschnitt wie folgt und gib die entsprechende Bezeichnung aus:

// Durchschnitt <= 0: "non-positive"
// Durchschnitt 1 bis 50: "low"
// Durchschnitt 51 bis 100: "medium"
// Über 100: "high"
// Da switch Bereiche nicht direkt verarbeiten kann, verwende eine if-else-if-Kette für diese Klassifizierung. Erkläre in einem Kommentar in deinem Code, warum switch hier nicht geeignet ist.

// c) Identifiziere zwei potenzielle Grenzfälle, die zu einem falschen Verhalten deines Programms führen könnten (zum Beispiel: Was passiert, wenn der Benutzer sofort 0 als ersten Wert eingibt?). Beschreibe jeden Grenzfall und erkläre, wie du dich in deinem Code dagegen absicherst.

// GCC- oder Clang-Compiler
// Ein Terminal / eine Kommandozeile
// Texteditor oder VS Code mit C/C++-Erweiterung
// ////////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>

int main(void){

    int input = 0;
    int sum = 0;
    int count = -1;

    printf("Enter your number or 0 for exit: ");
    scanf("%d", &input);
    int min = input;
    int max = input;
    do{
        sum += input;
        count++;
        if(input != 0 && input <= min){
            min = input;
        }
        if(input >= max && input != 0){
            max = input;
        }
        printf("Enter your number or 0 for exit: ");
        scanf("%d", &input);

    } while (input != 0);

    printf("Your sum is: %d \n", sum);
    printf("Your count is: %d \n", count);
    printf("Your minimum is: %d \n", min);
    printf("Your maximum is: %d \n", max);

    double durchschnitt = (double)sum/count;
    if(durchschnitt <= 0){
        printf("Your Durchschnitt is non-positive: %.2f \n", durchschnitt);
    } else if (durchschnitt <= 50){
        printf("Your Durchschnitt is low: %.2f \n", durchschnitt);
    } else if (durchschnitt <= 100){
        printf("Your Durchschnitt is medium: %.2f \n", durchschnitt);
    } else if (durchschnitt > 100){
        printf("Your Durchschnitt is high: %.2f \n", durchschnitt);
    }
}