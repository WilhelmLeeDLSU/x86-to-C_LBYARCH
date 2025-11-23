#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

extern void asmdistance(int n, double *x1, double *x2, double *y1, double *y2, double *z);

void calc_dist_c(int n, double *x1, double *x2, double *y1, double *y2, double *z) {
    for (int i = 0; i < n; i++) {
        double dx = x2[i] - x1[i];
        double dy = y2[i] - y1[i];
        z[i] = sqrt(dx*dx + dy*dy);
    }
}

int main() {
    //Input data
    int n = 3;
    double x1[] = {1.0, 2.5, 0.0};
    double x2[] = {4.0, 5.5, 0.0};
    double y1[] = {1.0, 1.0, 0.0};
    double y2[] = {5.0, 5.0, 10.0};

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