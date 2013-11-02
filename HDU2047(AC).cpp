#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

__int64 a[40][3];
__int64 res[40];

int main()
{
    int n;

    a[1][0] = a[1][1] = a[1][2] = 1;
    res[1] = 3;
    for(n = 2; n < 40; ++n){
        a[n][0] = a[n - 1][1] + a[n - 1][2];
        a[n][1] = a[n - 1][0] + a[n - 1][1] + a[n - 1][2];
        a[n][2] = a[n - 1][0] + a[n - 1][1] + a[n - 1][2];
        res[n] = a[n][0] +  a[n][1] + a[n][2];
    }

    while(scanf("%d", &n) == 1){
        printf("%I64d\n", res[n]);
    }

    return 0;
}

