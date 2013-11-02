#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
    int m, n;
    int t, ti;
    
    while(scanf("%d", &t) == 1){
        for(ti = 0; ti < t; ++ti){
            scanf("%d%d", &n, &m);
            printf("%d\n", (1 + n) * n / 2 * (1 + m) * m / 2);
        }
    }

    return 0;
}

