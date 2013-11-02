#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

__int64 c[21][21];
__int64 a[21];
int n, m;

__int64 combination(int n, int k)
{
    int i;
    __int64 res, sum;

    res = 1;
    sum = 1;
    for(i = 1; i <= k; ++i){
        res *= n + 1 - i;
        sum *= i;
        if(res % sum == 0){
            res = res / sum;
            sum = 1;
        }
    }
    if(res % sum == 0){
        res = res / sum;
        sum = 1;
    }

    return res;
}

int main()
{
    int i, j;
    int t, ti;

    for(i = 1; i <= 20; ++i){
        for(j = 0; j <= i; ++j){
            c[i][j] = combination(i, j);
        }
    }

    a[1] = 0;
    a[2] = 1;
    for(i = 3; i <= 20; ++i){
        a[i] = (i - 1) * (a[i - 1] + a[i - 2]);
    }

    while(scanf("%d", &t) == 1){
        for(ti = 0; ti < t; ++ti){
            scanf("%d%d", &n, &m);
            printf("%I64d\n", c[n][n - m] * a[m]);
        }
    }

    return 0;
}

