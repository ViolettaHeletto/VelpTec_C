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
/**/
/////////////////////////////////////////////////////////////////////////////////////////
/*
*/
/////////////////////////////////////////////////////////////////////////////////////////
/*
*/
/////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>


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
        printf("%-16s  €%.2f  stock: %d\n",

catalog[i].name, catalog[i].price, catalog[i].in_stock);
    }

    return 0;
}

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
    aufgabe2();
    return 0;
}
