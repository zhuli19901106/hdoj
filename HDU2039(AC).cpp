#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

double myabs(double a)
{
    if(a > 0){
        return a;
    }else{
        return -a;
    }
}

int main()
{
    double a, b, c;
    int t, ti;

    while(scanf("%d", &t) == 1){
        for(ti = 0; ti < t; ++ti){
            scanf("%lf%lf%lf", &a, &b, &c);
            if(a + b > c && b + c > a && c + a > b && myabs(a - b) < c && myabs(b - c) < a && myabs(c - a) < b){
                printf("YES\n");
            }else{
                printf("NO\n");
            }
        }
    }

    return 0;
}

