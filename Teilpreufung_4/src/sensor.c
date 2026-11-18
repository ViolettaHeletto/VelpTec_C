#include "sensor.h"
#include <stdio.h>
#include <stdlib.h>

void array_init(DynamicArray *a) {
    a->data = nullptr;
    a->size = 0;
    a->capacity = 0;
}

int  array_push(DynamicArray *a, SensorRecord record) {
    if(a->size == a->capacity){
        size_t new_capacity = (a->capacity == 0) ? 4 : a->capacity*2;
        SensorRecord *tmp = realloc(a->data, new_capacity * sizeof (*tmp));
        if(tmp == nullptr){
            return -1;
        }
        a->data = tmp;
        a->capacity = new_capacity;
    }
    a->data[a->size] = record;
    a->size++;
    return 0;
}

void array_destroy(DynamicArray *a) {
    free(a->data);
    a->data     = nullptr;
    a->size = 0;
    a->capacity = 0;
}

int  load_records(const char *path, DynamicArray *out) {//FILE
    FILE *f = fopen(path, "rb");
    if (f == NULL) {
        perror("fopen");
        return 1;
    }

    SensorRecord rec;
    while (fread(&rec, sizeof(SensorRecord), 1, f) == 1) {
        printf("ID: %2u | Temp: %5.1f | Hum: %5.1f | Status: %u\n",
               rec.id, rec.temperature, rec.humidity, rec.status_flags);
        array_push(out, rec);
    }

    if (ferror(f)) {
        perror("fread");
        fclose(f);
        return 1;
    }

    fclose(f);
    return 0;
}

int  filter_and_report(const DynamicArray *records,
                       float threshold,
                       const char *report_path) {
    int written = 0;
    int skipped = 0;
    FILE *report_file = fopen(report_path, "w");
    if (report_file == NULL) {
        perror("fopen");
        return -1;
    }
    for (size_t i = 0; i < records->size; i++) {
        const SensorRecord *r = &records->data[i];
        int to_hot = (r->temperature > threshold);
        int error = ((r->status_flags & PERM_STATUS_ERROR) != 0);
        if (to_hot && !error) {
            fprintf(report_file, "ID: %2u | Temp: %5.1f | Hum: %5.1f | Status: %u\n",
                    r->id, r->temperature, r->humidity, r->status_flags);
            ++written;
        } else {
            ++skipped;
        }
    }
    fprintf(report_file, "\nWritten items: %d | Skipped items: %d\n", written, skipped);
    if (ferror(report_file)) {
        perror("fwrite");
        fclose(report_file);
        return -1;
    }

    fclose(report_file);
    return 0;
}