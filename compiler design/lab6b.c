#include <stdio.h>
#include <time.h>

int main() {
    // Variables for the loop
    int a, b = 5, i;
    int c, d = 10, e = 20, f, g = 30, h = 40;

    // Time before loop jamming (Program 1)
    clock_t start_t1, end_t1;
    double total_t1;

    start_t1 = clock();

    // Program 1 (Before Loop Jamming)
    for (i = 0; i < 1000000000; i++) {
        a = b + i;    // Operation 1
        c = d + e;    // Operation 2
        f = g + h;    // Operation 3
    }

    end_t1 = clock();
    total_t1 = (double)(end_t1 - start_t1) / CLOCKS_PER_SEC;
    printf("Before Loop Jamming (t1): %.5f seconds\n", total_t1);

    // Time after loop jamming (Program 2)
    clock_t start_t2, end_t2;
    double total_t2;

    start_t2 = clock();

    // Program 2 (After Loop Jamming)
    // Move operations that do not depend on 'i' outside the loop
    c = d + e;  // Operation 2 (unchanged in each iteration)
    f = g + h;  // Operation 3 (unchanged in each iteration)

    // Loop only for operation on 'a'
    for (i = 0; i < 1000000000; i++) {
        a = b + i;    // Operation 1 (inside loop)
    }

    end_t2 = clock();
    total_t2 = (double)(end_t2 - start_t2) / CLOCKS_PER_SEC;
    printf("After Loop Jamming (t2): %.5f seconds\n", total_t2);

    // Time comparison
    printf("\nTime comparison:\n");
    printf("Before Loop Jamming (t1): %.5f seconds\n", total_t1);
    printf("After Loop Jamming (t2): %.5f seconds\n", total_t2);

    return 0;
}
