#include <stdio.h>
#include <time.h>

struct timespec start;
struct timespec end;
unsigned long long nsecs = 0;

#define start_iteration() \
    clock_gettime(CLOCK_MONOTONIC, &start);

#define end_iteration() \
    clock_gettime(CLOCK_MONOTONIC, &end); \
    nsecs += (end.tv_sec - start.tv_sec) * 1e9 + (end.tv_nsec - start.tv_nsec);

#define print_time() \
    fprintf(stderr, "%llu\n", nsecs / (unsigned long long)1e6);

