#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;
#define MAXN 12

int main()
{
    double fac[MAXN];
    double sum[MAXN];
    int i;

    fac[0] = 1;
    sum[0] = fac[0];
    for(i = 1; i < MAXN; i++)
    {
        fac[i] = fac[i - 1] * 1.0 / i;
        sum[i] = sum[i - 1] + fac[i];
    }

    printf("n e\n");
    printf("- -----------\n");
    for(i = 0; i <= 2; i++)
    {
        printf("%d %g\n", i, sum[i]);
    }
    for(i = 3; i <= 9; i++)
    {
        printf("%d %0.9f\n", i, sum[i]);
    }

    return 0;
}

