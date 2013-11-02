#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

inline double f(double x, double a, double b, double c)
{
    return a * x * x * x / 3.0 + b * x * x / 2.0 + c * x;
}

int main()
{
    double x1, y1, x2, y2, x3, y3;
    double a, b, c;
    int t, ti;

    while(scanf("%d", &t) == 1){
        for(ti = 0; ti < t; ++ti){
            scanf("%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &x3, &y3);
            a = (y2 - y1) / ((x2 - x1) * (x2 - x1));
            b = -2.0 * a * x1;
            c = y1 + a * x1 * x1;
            printf("%.2f\n", f(x3, a, b, c) - f(x2, a, b, c) - 0.5 * (x3 - x2) * (y3 + y2));
        }
    }

    return 0;
}

