#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

__int64 a[26];
__int64 res[26];

__int64 combination(int n, int k)
{
    __int64 res, sum;
    int i;

    if(k > n / 2){
        return combination(n, n - k);
    }

    res = 1;
    sum = 1;
    for(i = 1; i <= k; ++i){
        res = res * (n + 1 - i);
        sum = sum * i;
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
    int n;
    int i, j;
    /*
    //Just to check the combination function
    for(i = 1; i <= 10; ++i){
        for(j = 0; j <= i; ++j){
            printf("C[%d, %d] = %I64d\n", i, j, combination(i, j));
        }
    }
    */
    a[0] = 1;
    a[1] = 0;
    a[2] = 1;
    for(n = 3; n <= 12; ++n){
        a[n] = (n - 1) * (a[n - 1] + a[n - 2]);
    }
    res[1] = 1;
    res[2] = 1;
    for(i = 3; i <= 25; ++i){
        res[i] = 0;
        for(j = (i + 1) / 2; j <= i; ++j){
            res[i] += combination(i, j) * a[i - j];
        }
    }

    while(scanf("%d", &n) == 1 && n){
        printf("%I64d\n", res[n]);
    }

    return 0;
}

