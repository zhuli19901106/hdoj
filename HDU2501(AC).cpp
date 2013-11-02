#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int res[31];

int main()
{
    int i;
    int n, t, ti;

    res[0] = 1;
    res[1] = 1;
    for(i = 2; i <= 30; ++i){
        res[i] = res[i - 1] + 2 * res[i - 2];
    }

    while(scanf("%d", &t) == 1){
        for(ti = 0; ti < t; ++ti){
            scanf("%d", &n);
            printf("%d\n", res[n]);
        }
    }

    return 0;
}

