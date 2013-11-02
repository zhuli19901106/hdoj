#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

const int MAXN = 1000005;
int x[MAXN], y[MAXN];
int n;

int main()
{
    double a, cx, cy;
    double sumx, sumy, suma;
    int t, ti;
    int i;

    while(scanf("%d", &t) == 1){
        for(ti = 0; ti < t; ++ti){
            scanf("%d", &n);
            for(i = 0; i < n; ++i){
                scanf("%d%d", &x[i], &y[i]);
            }
            x[n] = x[0];
            y[n] = y[0];
            sumx = 0;
            sumy = 0;
            suma = 0;
            for(i = 0; i < n; ++i){
                a = (1.0 * x[i] * y[i + 1] - 1.0 * x[i + 1] * y[i]);
                cx = (1.0 * x[i] + x[i + 1]);
                cy = (1.0 * y[i] + y[i + 1]);
                suma += a;
                sumx += a * cx;
                sumy += a * cy;
            }
            sumx /= (3.0 * suma);
            sumy /= (3.0 * suma);

            printf("%.2f %.2f\n", sumx, sumy);
        }
    }

    return 0;
}

