#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
    int n;
    int a, b, c;
    int t, ti;

    while(scanf("%d", &t) == 1){
        for(ti = 0; ti < t; ++ti){
            scanf("%d", &n);
            a = n / 2;
            b = (int)((n - a) * 2.0 / 3.0);
            c = n - a - b;
            printf("%d\n", (a + 9) / 10 + (b + 9) / 10 + (c + 9) / 10);
        }
    }

    return 0;
}

