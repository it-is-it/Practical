#include <stdio.h>
#include <time.h>

int main() {
    int a, b = 1, c, d = 2, e = 3, f, g = 4, h = 5;

    // Measure time for Program 1 (before optimization)
    clock_t start_t1, end_t1;
    double total_t1;
    
    start_t1 = clock();
    
    // Before optimization: operations inside the loop
    for (int i = 0; i < 1000000000; i++) {
        a = b + i;   // Operation 1
        c = d + e;   // Operation 2 (no dependency on i)
        f = g + h;   // Operation 3 (no dependency on i)
    }
    
    end_t1 = clock();
    total_t1 = (double)(end_t1 - start_t1) / CLOCKS_PER_SEC;
    
    printf("Before optimization (t1): %.2f seconds\n", total_t1);

    // Measure time for Program 2 (after optimization)
    clock_t start_t2, end_t2;
    double total_t2;

    start_t2 = clock();

    // After optimization: move the operations outside the loop
    c = d + e;   // Operation 2 (no dependency on i)
    f = g + h;   // Operation 3 (no dependency on i)

    for (int i = 0; i < 1000000000; i++) {
        a = b + i;   // Operation 1 (dependent on i)
    }

    end_t2 = clock();
    total_t2 = (double)(end_t2 - start_t2) / CLOCKS_PER_SEC;
    
    printf("After optimization (t2): %.2f seconds\n", total_t2);

    return 0;
}
