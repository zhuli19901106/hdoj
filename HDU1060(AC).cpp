#define _CRT_SECURE_NO_WARNINGS
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
    int n, res;
    __int64 d;
    int t, ti;

    while(scanf("%d", &t) == 1){
        for(ti = 0; ti < t; ++ti){
            scanf("%d", &n);
            d = (__int64)(n * log10(1.0 * n)) + 1;
            res = (int)pow(10.0, n * log10(1.0 * n) - d + 1);
            printf("%d\n", res);
        }
    }

    return 0;
}

