// int32_t *values = malloc(MAX_RECORDS * sizeof(int32_t)); 
// if (values == NULL) { 
//     fprintf(stderr, "Error: failed to allocate memory for %d records\n", MAX_RECORDS); 
//     return EXIT_FAILURE; 
// } 

// typedef struct { 
//     int32_t min; 
//     int32_t max; 
//     int64_t sum;     // wider type to avoid overflow when summing 1000 values 
//     double  mean; 
// } Stats;

// // Globales Flag (Dateibereich): 
// volatile sig_atomic_t keep_running = 1; 
 
// // Signal-Handler: 
// void handle_sigint(int sig) { 
//     (void)sig;          // suppress unused-parameter warning 
//     keep_running = 0;   // set flag; do nothing else 
// } 
 
// // In main, vor der Leseschleife: 
// signal(SIGINT, handle_sigint); 
 
// // Leseschleife: 
// for each line in input file: 
//     if (!keep_running) break;   // check flag every iteration 
//     read and parse the line 
//     store value in buffer 
 
// if (!keep_running): 
//     fprintf(stderr, "Interrupted. Partial data discarded.\n") 
//     free buffer and close file 
//     exit(EXIT_FAILURE) 

// // e) Makefile 

// // CC      = gcc 
// // CFLAGS  = -Wall -Wextra -std=c23 
// // TARGET  = summarize 
// // OBJECTS = main.o stats.o 
 
// // $(TARGET): $(OBJECTS) 
// //     $(CC) $(OBJECTS) -o $(TARGET) 
 
// // main.o: main.c stats.h 
// //     $(CC) $(CFLAGS) -c main.c -o main.o 
 
// // stats.o: stats.c stats.h 
// //     $(CC) $(CFLAGS) -c stats.c -o stats.o 
 
// // .PHONY: clean 
 
// // clean: 
// //     rm -f $(TARGET) $(OBJECTS) 