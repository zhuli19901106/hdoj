#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
    int n, i;
    double res;

    while(scanf("%d", &n) == 1 && n){
        res = n;
        for(i = 2; i <= n; ++i){
            res += (1.0 * (2 * (n + 1 - i)) / i);
        }
        printf("%.2f\n", res);
    }

    return 0;
}

