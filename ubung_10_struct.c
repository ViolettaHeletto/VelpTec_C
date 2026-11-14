/*
Übung 10.2.Ü.01
Abschlussbedingungen
 Erledigt: Anzeigen
Aufgabe: Structs mit Zeigern und Funktionen definieren und verwenden
Definiere einen Student-Struct mit den folgenden Mitgliedern: 
name — ein Zeichenarray mit 50 Zeichen 
student_id — ein int
grade — ein double 
Wende den Struct dann in den folgenden Teilaufgaben an. 

a) Deklariere und initialisiere zwei Student-Variablen mit designierten Initialisierern. Ein Student namens "Maria Müller" mit der ID 1001 und der Note 1.7, und ein weiterer namens "Tom Fischer" mit der ID 1002 und der Note 2.3. Gib die Daten beider Studenten mit printf auf dem Terminal aus. 

b) Schreibe eine Funktion print_student, die einen Zeiger auf einen Student entgegennimmt (verwende const Student *) und Name, ID und Note des Studenten ausgibt. Rufe diese Funktion für beide Studenten auf. 

c) Schreibe eine Funktion improve_grade, die einen Zeiger auf einen Student und einen double-Verbesserungswert entgegennimmt. Die Funktion soll den Verbesserungswert von der Note des Studenten abziehen (niedrigere Note = besser im deutschen Notensystem), darf die Note aber nicht unter 1.0 fallen lassen. Rufe die Funktion für "Tom Fischer" mit einer Verbesserung von 0.5 auf und gib seine aktualisierte Note aus. 
*/
/*
typedef struct { 
    char   name[50]; 
    int    student_id; 
    double grade; 
} Student; 
 void print_student(const Student *s) { 
    printf("Name: %s, ID: %d, Grade: %.1f\n", s->name, s->student_id, s->grade); 
} 
int main(void) { 
    Student s1 = {.name = "Maria Müller", .student_id = 1001, .grade = 1.7}; 
    Student s2 = {.name = "Tom Fischer",  .student_id = 1002, .grade = 2.3}; 
 
    printf("Name: %s, ID: %d, Grade: %.1f\n", s1.name, s1.student_id, s1.grade); 
    printf("Name: %s, ID: %d, Grade: %.1f\n", s2.name, s2.student_id, s2.grade); 
 
print_student(&s1); 
print_student(&s2); 
    return 0; 
} 

*/
/////////////////////////////////////////////////////////////////////////////////////////
/*
Übung 10.4.Ü.01
Abschlussbedingungen
 Erledigt: Anzeigen
Aufgabe: Unions, Enums und Tagged Variants in C verstehen 

Erkläre den Unterschied zwischen einem struct und einer union in C. Beschreibe, wann du eine Union einer Struct vorziehen würdest, und erkläre, warum eine einfache Union ohne begleitendes Tag als unsicher gilt. 

Wende dann dein Verständnis auf das folgende Szenario an: Du entwirfst einen Datentyp zur Darstellung eines Konfigurationswerts, der einen von drei Typen halten kann — eine Ganzzahl, eine Gleitkommazahl oder ein boolesches Flag. Implementiere das als Tagged Union in C. 

a) Erkläre in eigenen Worten, wie sich eine Union von einer Struct in Bezug auf das Speicherlayout unterscheidet. Warum ist sizeof(union) für dieselben Mitglieder typischerweise kleiner als sizeof(struct)? 

b) Beschreibe das Problem bei der Verwendung einer einfachen Union (ohne Tag) und erkläre, wie eine Tagged Union (struct + enum + union) es löst. 

c) Definiere eine C-Tagged-Union namens ConfigValue, die jeweils einen der folgenden Typen speichert:
 
int (für Integer-Einstellungen) 

double (für Dezimaleinstellungen) 

int als boolesches Flag verwendet (für Ein/Aus-Einstellungen) 

Verwende ein typedef enum, um den Typ-Tag mit den Werten CONFIG_INT, CONFIG_DOUBLE und CONFIG_BOOL zu definieren. Fasse den Enum-Tag und die Union zusammen in einem typedef struct.

d) Schreibe den C-Code, um eine ConfigValue-Variable zu deklarieren, die den ganzzahligen Wert 42 hält, und schreibe einen Code-Ausschnitt mit einer if- oder switch-Anweisung, der den Tag prüft und den Wert im richtigen Format ausgibt. 
*/
/////////////////////////////////////////////////////////////////////////////////////////
/*
Übung 10.4.Ü.02
c) Definiere ein C-Enum namens ShapeType mit den Werten SHAPE_CIRCLE, SHAPE_RECTANGLE und SHAPE_TRIANGLE. Weise explizite ganzzahlige Werte ab 1 zu. Definiere dann eine Tagged Union Shape, die dieses Enum als Tag mit einer Union kombiniert, die folgende Member enthält: 

circle — ein struct mit einem einzelnen double-Member radius 

rectangle — ein struct mit den double-Membern width und height 

triangle — ein struct mit einem einzelnen double-Member base und einem einzelnen double-Member height 

Schreibe eine Code-Skizze, die zeigt, wie du eine Shape-Variable für einen Kreis mit dem Radius 5.0 deklarierst und dann radius sicher liest, indem du zuerst den Tag prüfst. 

d) Erkläre, was typisierte Enums in C23 sind, welches Problem sie im Vergleich zu einem einfachen enum lösen, und gib ein kurzes Beispiel mit der Syntax zur Deklaration eines typisierten Enums mit unsigned char als zugrundeliegendem Typ. 

*/
/////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>

/*Aufgabe 4*/
typedef enum {
    SHAPE_CIRCLE    = 1,
    SHAPE_RECTANGLE = 2,
    SHAPE_TRIANGLE  = 3
} ShapeType;

typedef struct {
    ShapeType type;   /* tag: welche Form gerade aktiv ist */
    union {
        struct { double radius; }         circle;
        struct { double width; double height; } rectangle;
        struct { double base;  double height; } triangle;
    } data;
} Shape;

void aufgabe4() {
    /* Einen Kreis mit Radius 5.0 deklarieren */
    Shape s = {
        .type        = SHAPE_CIRCLE,
        .data.circle = { .radius = 5.0 }
    };

    /* radius sicher lesen, indem zuerst der Tag geprüft wird */
    if (s.type == SHAPE_CIRCLE) {
        printf("Radius: %.2f\n", s.data.circle.radius);
    }
}

/*Aufgabe 3*/

typedef enum {TYPE_INT, TYPE_DOUBLE, TYPE_BOOL} ValueType;

typedef struct {
    ValueType type;
    union {
        int as_int;
        double as_double;
        bool as_bool;
    }value;

}ConfigValue;

void aufgabe3() {
    ConfigValue v = {.type = TYPE_INT, .value.as_int = 42};
    switch (v.type)
    {
    case TYPE_INT:
        printf("Integer setting: %d\n", v.value.as_int);
        break;
    case TYPE_DOUBLE:
        printf("Decimal setting: %f\n", v.value.as_double);
        break;
    case TYPE_BOOL:
        printf("Boolean setting: %s\n", v.value.as_bool ? "true" : "false");
        break;
    };
}

/*Aufgabe 2*/
typedef struct {
    char   name[64];
    double price;
    int    in_stock;
} Product;

void aufgabe2() {
    Product catalog[3] = {
        {.name = "Coffee Beans",  .price = 12.99, .in_stock = 40},
        {.name = "Green Tea",     .price =  8.49, .in_stock =  0},
        {.name = "Hot Chocolate", .price = 10.75, .in_stock = 15}
    };

    for (int i = 0; i < 3; i++) {
        printf("%-16s  €%.2f  stock: %d\n", catalog[i].name, catalog[i].price, catalog[i].in_stock);
    }
}

/*Aufgabe 1*/
typedef struct {
    char name [50];
    int student_id;
    double grade;
} Mitglieder;

void  print_student(Mitglieder *s, size_t size){
    for (size_t i = 0; i < size; i++)
    {
        printf("%s: ID - %d, Grade - %.2f\n", s[i].name, s[i].student_id, s[i].grade);
    }
}

void improve_grade(Mitglieder *s, double improve){
    s->grade -= improve;
    if (s->grade <= 1.0)
    {
        s->grade = 1.0;
    }
}

void aufgabe1(){
    Mitglieder student[2] = {
                            { .name = "Maria Mueller", .student_id = 1001 , .grade = 1.7 },
                            { .name = "Tom Fische",  .student_id = 1002, .grade = 2.3 }
    };
    print_student(student, sizeof(student)/sizeof(student[0]));
    improve_grade(&student[1], 0.5);
    print_student(student, sizeof(student)/sizeof(student[0]));
    improve_grade(&student[1], 0.5);
    print_student(student, sizeof(student)/sizeof(student[0]));
    improve_grade(&student[1], 0.5);
    print_student(student, sizeof(student)/sizeof(student[0]));
}

int main(void){
    aufgabe3();
    return 0;
}
