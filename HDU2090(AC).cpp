#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

char s[1000];
double a, b, sum;

int main()
{
    sum = 0;
    while(scanf("%s", s) == 1){
        scanf("%lf%lf", &a, &b);
        //sum += ((int)(a * b * 10.0 + 0.5)) / 10.0;
        sum += a * b;
    }

    printf("%.1f\n", sum);

    return 0;
}

