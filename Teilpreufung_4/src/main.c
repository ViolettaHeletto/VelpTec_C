#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "sensor.h"

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input.bin> <output.txt> <threshold>\n", argv[0]);
        return 1;
    }

    const char *in_file = argv[1];
    const char *out_file = argv[2];

    char *endptr;
    errno = 0;
    double threshold = strtod(argv[3], &endptr);
    if (errno != 0 || endptr == argv[3] || *endptr != '\0') {
        fprintf(stderr, "Fehler: Ungültiger Schwellenwert '%s'\n", argv[3]);
        return 1;
    }

    DynamicArray out;
    array_init(&out);

    if (load_records(in_file, &out) != 0) {
        array_destroy(&out);
        return 1;
    }

    if (filter_and_report(&out, (float)threshold, out_file) != 0) {
        fprintf(stderr, "Fehler bei filter_and_report\n");
        array_destroy(&out);
        return 1;
    }

    printf("Bericht erfolgreich in %s geschrieben!\n", out_file);
    array_destroy(&out);
    return 0;
}