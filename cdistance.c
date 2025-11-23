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
    long long n = 4;
    double x1[] = {1.5, 4.0, 3.5, 2.0};
    double x2[] = {3.0, 2.5, 2.5, 1.0};
    double y1[] = {4.0, 3.0, 3.5, 3.0};
    double y2[] = {2.0, 2.5, 1.0, 1.5};

    //Z
    double z[n];

    asmdistance(n, x1, x2, y1, y2, z);
    printf("Assembly distances:\n");
    for (int i = 0; i < n; i++) {
        printf("Distance %d: %lf\n", i, z[i]);
    }

    calc_dist_c(n, x1, x2, y1, y2, z);
    printf("C distances:\n");
    for (int i = 0; i < n; i++) {
        printf("Distance %d: %lf\n", i, z[i]);
    }


    return 0;
}