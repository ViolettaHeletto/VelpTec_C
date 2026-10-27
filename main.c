#include <stdio.h>
#include <limits.h>
// INT_MAX, INT_MIN, etc.
int main(void) {
    int x = INT_MAX;
    // 2147483647
    unsigned int y = UINT_MAX;
    // 4294967295
    printf("Max          int: %d\n", x);
    printf("Max unsigned int: %u\n", y);
    return 0;
}