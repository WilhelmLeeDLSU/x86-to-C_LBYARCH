#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

extern void asmdistance(long long n, double *x1, double *x2, double *y1, double *y2, double *z);

void calc_dist_c(long long n, double *x1, double *x2, double *y1, double *y2, double *z) {
    for (int i = 0; i < n; i++) {
        double dx = x2[i] - x1[i];
        double dy = y2[i] - y1[i];
        z[i] = sqrt(dx*dx + dy*dy);
    }
}

int main() {
    //Input data
    long long n = 1 << 24; 
    printf("Benchmarking with N = %lld elements\n", n);

    double *x1 = (double*)malloc(n * sizeof(double));
    double *x2 = (double*)malloc(n * sizeof(double));
    double *y1 = (double*)malloc(n * sizeof(double));
    double *y2 = (double*)malloc(n * sizeof(double));

    double *z_c = (double*)malloc(n * sizeof(double));
    double *z_asm = (double*)malloc(n * sizeof(double));

    printf("Generating random data\n");
    for (long long i = 0; i < n; i++) {
        x1[i] = (double)(rand() % 100);
        x2[i] = (double)(rand() % 100);
        y1[i] = (double)(rand() % 100);
        y2[i] = (double)(rand() % 100);
    }

    clock_t start, end;
    double cpu_time_used;

    //ASM Benchmark
    printf("\nRunning ASM function\n");
    start = clock();
    asmdistance(n, x1, x2, y1, y2, z_asm);
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("ASM Version Time: %.4f seconds\n", cpu_time_used);

    //C Benchmark
    printf("\nRunning C function...\n");
    start = clock();
    calc_dist_c(n, x1, x2, y1, y2, z_c);
    end = clock();
    
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("C Version Time:   %.4f seconds\n", cpu_time_used);

    //Correctness Checking
    int ver = 10; // Number of elements to verify
    printf("\nVerification (First %d):\n", ver);
    int correct = 1;
    for (int i = 0; i < ver; i++) {
        printf("Index %d - C: %.2f | ASM: %.2f\n", i, z_c[i], z_asm[i]);
        if (fabs(z_c[i] - z_asm[i]) > 0.0001) correct = 0;
    }
    
    if (correct) printf("\n[SUCCESS] Results match\n");
    else printf("\n[ERROR] Results do not match\n");

    free(x1); free(x2); free(y1); free(y2); free(z_c); free(z_asm);

    return 0;
}