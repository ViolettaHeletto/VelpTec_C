#ifndef SENSOR_H
#define SENSOR_H

#include <stdint.h>   // uint32_t, uint8_t
#include <stddef.h>   // size_t (в C++ придёт и из других, но явно лучше)

typedef struct {
    uint32_t id;
    float temperature;
    float humidity;
    uint8_t status_flags;
}SensorRecord;

/*Ein typisiertes Enum SensorStatus mit unsigned char als zugrunde liegendem Typ
und den Werten STATUS_OK = 0, STATUS_WARN = 1, STATUS_ERROR = 2*/
typedef enum : unsigned char {
    STATUS_OK = 0,
    STATUS_WARN = 1,
    STATUS_ERROR = 2
}SensorStatus;

/*Ein Struct DynamicArray mit den Feldern: SensorRecord *data, size_t size, size_t capacity */
typedef struct {
    SensorRecord *data;
    size_t size;
    size_t capacity;
}DynamicArray;

/*Funktionsprototypen für: array_init, array_push, array_destroy, load_records, filter_and_report */
void array_init(DynamicArray *a);
int  array_push(DynamicArray *a, SensorRecord record);
void array_destroy(DynamicArray *a);

int  load_records(const char *path, DynamicArray *out);
int  filter_and_report(const DynamicArray *records,
                       float threshold,
                       const char *report_path);

#endif /* SENSOR_H */