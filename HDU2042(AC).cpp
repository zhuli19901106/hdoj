#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

__int64 a[31];

int main()
{
    int n;
    int t, ti;

    a[0] = 3;
    for(n = 1; n <= 30; ++n){
        a[n] = (a[n - 1] - 1) * 2;
    }

    while(scanf("%d", &t) == 1){
        for(ti = 0; ti < t; ++ti){
            scanf("%d", &n);
            printf("%I64d\n", a[n]);
        }
    }

    return 0;
}

