#define _CRT_SECURE_NO_WARNINGS
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

const double pi = 3.1415926;
double d, D;
double r, R;
double s;

int main()
{
    int t, ti;

    while(scanf("%d", &t) == 1){
        for(ti = 0; ti < t; ++ti){
            scanf("%lf%lf%lf", &D, &d, &s);
            R = D / 2;
            r = d / 2;

            if(r > R){
                printf("0\n");
                continue;
            }

            if(D - d < s){
                printf("1\n");
                continue;
            }

            printf("%d\n", (int)floor(2 * pi / (acos(1.0 - (s + d) * (s + d) / (2 * (R - r) * (R - r))))));
        }
    }

    return 0;
}

