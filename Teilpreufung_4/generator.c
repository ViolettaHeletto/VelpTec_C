#include <stdio.h>
#include <stdint.h>

typedef struct {
    uint32_t id;
    float temperature;
    float humidity;
    uint8_t status_flags;
} SensorRecord;

int main(void) {
    FILE *f = fopen("sensors.bin", "wb");
    if (!f) {
        perror("Fehler beim Erstellen der Datei");
        return 1;
    }

    SensorRecord records[] = {
        {1, 21.5f, 45.0f, 0},
        {2, 25.0f, 50.0f, 1},
        {3, 30.5f, 60.0f, 0},
        {4, 35.0f, 55.0f, 2},
        {5, 18.0f, 40.0f, 0},
        {6, 40.0f, 70.0f, 3},
        {7, 22.0f, 48.0f, 0},
        {8, 27.5f, 52.0f, 1},
        {9, 15.0f, 35.0f, 0},
        {10, 33.0f, 65.0f, 2},
        {11, 24.0f, 49.0f, 0},
        {12, 28.0f, 53.0f, 0}
    };

    size_t count = sizeof(records) / sizeof(records[0]);

    size_t written = fwrite(records, sizeof(SensorRecord), count, f);

    if (written != count) {
        perror("Fehler beim Schreiben");
        fclose(f);
        return 1;
    }

    fclose(f);
    printf("Erfolgreich %zu Datensätze in sensors.bin geschrieben.\n", count);
    return 0;
}