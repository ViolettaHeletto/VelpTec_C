/*
Teilprüfung 3
Abschlussbedingungen
Zu erledigen: Abgabe einreichen Zu erledigen: Eine Bewertung erhalten
K4.0021_4.0_10.4.A.01

Aufgabe
Du hast eine Stufe im Kurs erreicht, auf der du alles bisher Gelernte kombinieren kannst: Variablen und Datentypen, Kontrollfluss, Schleifen, Arrays, Strings, Funktionen, Zeiger, dynamischer Speicher und strukturierte Datentypen. Diese Transferaufgabe fordert dich heraus, ein kleines, aber vollständiges dynamisches Datensatzsystem zu entwerfen, zu implementieren und zu analysieren, das all diese Themen miteinander verbindet. 

Gegeben ist folgendes Szenario: Ein kleines Inventar-Tracking-Tool soll eine Sammlung von Produktdatensätzen verwalten. Jedes Produkt hat eine ID, einen Namen, einen Preis und eine Kategorie. Die Anzahl der Produkte ist zur Kompilierzeit nicht bekannt — sie wächst dynamisch, wenn neue Produkte hinzugefügt werden. 
Deine Aufgabe: Entwirf, implementiere und analysiere das Programm, das in den folgenden Teilaufgaben beschrieben wird.
a) Struct- und Enum-Design
Definiere ein C-Enum namens Category, das unsigned char als zugrundeliegenden Typ verwendet (C23 Typed Enum) und mindestens vier Kategorien enthält: CAT_ELECTRONICS, CAT_CLOTHING, CAT_FOOD und CAT_OTHER. Weise explizite ganzzahlige Werte beginnend ab 0 zu.
Definiere dann einen Struct namens Product mit typedef und den folgenden Mitgliedern (geordnet vom größten zum kleinsten Alignment, um Padding zu minimieren):
price als double
id als int
category als Category
name als char-Array mit 64 Zeichen
Erkläre schriftlich, warum die von dir gewählte Mitgliederreihenfolge Padding-Verschwendung im Vergleich zu einer naiven Reihenfolge minimiert, bei der char name[64] zuerst kommt, gefolgt von char category, dann int id, dann double price. Verwende sizeof-Überlegungen zur Begründung. 
b) Dynamisches Array von Produkten
Definiere einen Struct namens ProductStore, der ein dynamisches Array von Product-Datensätzen verwaltet. Er muss Folgendes enthalten:
einen Zeiger auf Product (für das heap-allozierte Array)
ein size_t-Feld für die Anzahl der aktuell gespeicherten Produkte
ein size_t-Feld für die allozierte Kapazität
Schreibe zwei Funktionen:
store_init(ProductStore *s) — initialisiert den Store in einen leeren, gültigen Zustand mit null Größe, null Kapazität und einem nullptr-Datenzeiger. 
store_push(ProductStore *s, Product p) — fügt ein neues Produkt an den Store an. Wenn die Kapazität erreicht ist, verdopple die Kapazität (beginne mit Kapazität 4, wenn aktuell 0). Verwende realloc korrekt mit einem temporären Zeiger, um das ursprüngliche Allocation bei Fehlschlag nicht zu verlieren. Gib true bei Erfolg und false bei Fehlschlag zurück. 
c) Such-, Filter- und Anzeigefunktionen
Schreibe die folgenden drei Funktionen:
print_product(const Product *p) — gibt die Felder eines einzelnen Produkts in lesbarem Format auf stdout aus. Verwende const Product *, um zu signalisieren, dass die Funktion das Produkt nicht verändert. Verwende printf mit passenden Format-Spezifizierern (%d, %s, %.2f). 
find_by_id(const ProductStore *s, int id) — durchsucht den Store nach einem Produkt mit passender id. Gibt einen const Product *-Zeiger auf das gefundene Produkt zurück oder nullptr, wenn nichts gefunden wurde. Verwende eine for-Schleife und Zeigervergleich. 
filter_by_category(const ProductStore *s, Category cat, ProductStore *out) — iteriert über alle Produkte in s und fügt diejenigen, die cat entsprechen, in den Ausgabe-Store out ein (der bereits initialisiert sein muss). Gibt die Anzahl der übereinstimmenden Produkte als intzurück. 
d) Speicherverwaltung und Aufräumen
Schreibe eine Funktion store_destroy(ProductStore *s), die den dynamisch allozierten Speicher im Store freigibt und alle Felder auf ihren Null-/Null-Ausgangszustand zurücksetzt. Erkläre schriftlich, was passieren würde, wenn du store_destroy zweimal auf demselben Store aufrufst, ohne den Zeiger nach dem ersten Aufruf auf nullptr zu setzen (Double-Free-Szenario), und wie das Setzen von s->data = nullptr nach free das verhindert. 
e) Analyse: Struct-Padding und Speicherbedarf
Berechne anhand der Struct-Definition aus Teilaufgabe (a) den gesamten Speicherbedarf in Bytes für einen ProductStore, der genau 100 Produkte hält. Zeige deine Berechnung anhand von sizeof(Product)-Überlegungen. Beantworte dann: Wenn du char name[64] als erstes Mitglied in Product platziert hättest, wie groß wäre sizeof(Product) auf einem typischen 64-Bit-System, und wie viel zusätzlichen Speicher würden 100 Produkte verschwenden? 
*/
#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

/* ---------- a) Struct- und Enum-Design ---------- */

/*
 * Category: C23 Typed Enum mit unsigned char als zugrundeliegendem Typ.
 * Explizite Werte ab 0, damit die numerischen Werte stabil bleiben,
 * auch wenn später neue Kategorien eingefügt werden.
 */

typedef enum : unsigned char {
    CAT_ELECTRONICS = 0,
    CAT_CLOTHING    = 1,
    CAT_FOOD        = 2,
    CAT_OTHER       = 3
} Category;

/*
 * Product: Felder nach absteigendem Alignment sortiert (double, int,
 * Category, char[64]). Dadurch entsteht nur Tail-Padding am Ende
 * (sizeof == 80 statt 77+3), aber kein internes Padding zwischen
 * den Feldern. Bei der naiven Reihenfolge (name zuerst, dann category,
 * id, price) müsste der Compiler nach category 3 Byte Padding einfügen,
 * damit id auf einer 4-Byte-Grenze liegt — das ist verschwendeter
 * Speicher mitten in der Struktur.
 */
typedef struct {
    double price;
    int id;
    Category category;
    char name[64];
} Product;

/* ---------- b) Dynamisches Array von Produkten ---------- */

/*
 * ProductStore: verwaltet ein heap-alloziertes, dynamisch wachsendes
 * Array von Product-Datensätzen.
 *   data                 — Zeiger auf das Array (nullptr, wenn leer)
 *   quantity_of_products — Anzahl der aktuell gespeicherten Produkte
 *   allocated_capacity   — aktuell allozierte Kapazität (>= quantity)
 */

typedef struct{
    Product *data;
    size_t quantity_of_products;
    size_t allocated_capacity;
} ProductStore;


void store_init(ProductStore *s); //initialisiert den Store in einen leeren, gültigen Zustand mit null Größe,
                                  //null Kapazität und einem nullptr-Datenzeiger.

bool store_push(ProductStore *s, Product p); //fügt ein neues Produkt an den Store an. Wenn die Kapazität erreicht ist,
                                             // verdopple die Kapazität (beginne mit Kapazität 4, wenn aktuell 0).
                                             // Verwende realloc korrekt mit einem temporären Zeiger,
                                             // um das ursprüngliche Allocation bei Fehlschlag nicht zu verlieren.
                                             // Gib true bei Erfolg und false bei Fehlschlag zurück.

void print_product(const Product *p); //gibt die Felder eines einzelnen Produkts in lesbarem Format auf stdout aus.
                                      //Verwende const Product *, um zu signalisieren, dass die Funktion das Produkt
                                      //nicht verändert. Verwende printf mit passenden Format-Spezifizierern (%d, %s, %.2f).

const Product *find_by_id(const ProductStore *s, int id); //durchsucht den Store nach einem Produkt mit passender id.
                                                   //Gibt einen const Product *-Zeiger auf das gefundene Produkt zurück
                                                   //oder nullptr, wenn nichts gefunden wurde. Verwende eine for-Schleife und Zeigervergleich.

int filter_by_category(const ProductStore *s, Category cat, ProductStore *out); //iteriert über alle Produkte in s und fügt diejenigen,
                                                                               //die cat entsprechen, in den Ausgabe-Store out ein
                                                                               //(der bereits initialisiert sein muss). Gibt die Anzahl
                                                                               //der übereinstimmenden Produkte als int zurück.

void store_destroy(ProductStore *s); //die den dynamisch allozierten Speicher im Store freigibt und
                                     //alle Felder auf ihren Null-/Null-Ausgangszustand zurücksetzt

int main(void){
    /* Store für alle Produkte anlegen und initialisieren. */
    ProductStore store;
    store_init(&store);

    /* Ein paar Testprodukte mit unterschiedlichen Kategorien. */
    Product p1 = { .price = 999.99, .id = 1, .category = CAT_ELECTRONICS, .name = "Laptop" };
    Product p2 = { .price =  29.99, .id = 2, .category = CAT_CLOTHING,    .name = "T-Shirt" };
    Product p3 = { .price =   2.49, .id = 3, .category = CAT_FOOD,        .name = "Apfel" };
    Product p4 = { .price = 149.00, .id = 4, .category = CAT_ELECTRONICS, .name = "Kopfhoerer" };
    Product p5 = { .price =   0.99, .id = 5, .category = CAT_FOOD,        .name = "Brot" };

    /* Produkte in den Store einfügen; bei Fehler abbrechen. */
    if (!store_push(&store, p1) || !store_push(&store, p2) ||
        !store_push(&store, p3) || !store_push(&store, p4) ||
        !store_push(&store, p5)){
        fprintf(stderr, "Fehler: store_push fehlgeschlagen\n");
        store_destroy(&store);
        return 1;
    }

    /* Alle Produkte ausgeben. */
    printf("--- Alle Produkte (%zu) ---\n", store.quantity_of_products);
    for (size_t i = 0; i < store.quantity_of_products; i++){
        print_product(&store.data[i]);
    }

    /* Suche nach ID 3 (vorhanden) und ID 99 (nicht vorhanden). */
    printf("\n--- Suche nach ID 3 ---\n");
    const Product *found = find_by_id(&store, 3);
    if (found != nullptr){
        print_product(found);
    } else {
        printf("Nicht gefunden.\n");
    }

    printf("\n--- Suche nach ID 99 ---\n");
    found = find_by_id(&store, 99);
    if (found != nullptr){
        print_product(found);
    } else {
        printf("Nicht gefunden.\n");
    }

    /* Nur Lebensmittel in einen separaten Store filtern. */
    ProductStore food;
    store_init(&food);   /* out muss vor dem Aufruf initialisiert sein */

    int n = filter_by_category(&store, CAT_FOOD, &food);
    if (n < 0){
        fprintf(stderr, "Fehler: filter_by_category fehlgeschlagen\n");
        store_destroy(&food);
        store_destroy(&store);
        return 1;
    }

    printf("\n--- Gefilterte Lebensmittel (%d) ---\n", n);
    for (size_t i = 0; i < food.quantity_of_products; i++){
        print_product(&food.data[i]);
    }

    /* Aufräumen: beide Stores freigeben. */
    store_destroy(&food);
    store_destroy(&store);

    /*
     * Zusätzlicher Test: store_destroy auf einem bereits zerstörten
     * Store darf nicht abstürzen. Mit s->data = nullptr in
     * store_destroy ist das ein sicherer No-Op (free(nullptr)).
     */
    store_destroy(&store);

    printf("\nFertig.\n");
    return 0;
}

void store_init(ProductStore *s){
    s->data = nullptr;
    s->quantity_of_products = 0;
    s->allocated_capacity = 0;
}

bool store_push(ProductStore *s, Product p){
    if(s->quantity_of_products == s->allocated_capacity){
        size_t new_capacity = 0;
        if(s->allocated_capacity == 0){
            new_capacity = 4;
        } else {
            new_capacity = s->allocated_capacity * 2;
        }
        Product *tmp = realloc(s->data, sizeof(Product) * new_capacity);
        if(tmp == nullptr){
            return false;
        }
        s->data = tmp;
        s->allocated_capacity = new_capacity;
    }
    s->data[s->quantity_of_products] = p;
    s->quantity_of_products++;
    return true;
}

void print_product(const Product *p){
    printf("ID: %d | Name: %s | Preis: %.2f | Kategorie: %d\n",
           p->id, p->name, p->price, (int)p->category);
}

const Product *find_by_id(const ProductStore *s, int id){
    for(size_t i = 0; i < s->quantity_of_products; i++){
        if (s->data[i].id == id){
            return &s->data[i];
        }
    }
    return nullptr;
}

int filter_by_category(const ProductStore *s, Category cat, ProductStore *out){
    int count = 0;
    for(size_t i = 0; i < s->quantity_of_products; i++){
        if (s->data[i].category == cat){
            if (!store_push(out, s->data[i])){
                return -1;
            }
            count++;
        }
    }
    return count;
}

void store_destroy(ProductStore *s){
    free(s->data);
    s->data = nullptr;
    s->quantity_of_products = 0;
    s->allocated_capacity = 0;
}

/* ---------- e) Analyse: Struct-Padding und Speicherbedarf ----------
 *
 * sizeof(Product) = 80 Byte (siehe Layout-Kommentar bei Product).
 * Für 100 Produkte im ProductStore:
 *   Array:   100 * sizeof(Product) = 100 * 80 = 8000 Byte
 *   Struct ProductStore selbst: sizeof(ProductStore) = 24 Byte
 *     (8 Byte Zeiger + 8 Byte size_t + 8 Byte size_t, kein Padding)
 *   Gesamt (Heap + Store-Objekt): 8000 + 24 = 8024 Byte.
 *   (Je nach Aufgabenstellung zählt nur der Heap-Anteil: 8000 Byte.)
 *
 * Naive Reihenfolge (char name[64], char category, int id, double price):
 *   offset 0..63: name
 *   offset 64:    category
 *   offset 65..67: 3 Byte Padding
 *   offset 68..71: id
 *   offset 72..79: price
 *   => sizeof(Product) == 80 Byte.
 *
 * In diesem konkreten Fall ist sizeof(Product) in beiden Varianten 80,
 * d. h. für 100 Produkte ergibt sich KEIN zusätzlicher Speicherverbrauch
 * (0 Byte Verschwendung). Der Unterschied liegt im internen Padding
 * (3 Byte mitten in der Struktur), das bei der gewählten Reihenfolge
 * vermieden wird. Bei anderen Feldgrößen (z. B. name[60]) wäre die
 * naive Variante größer.
 */