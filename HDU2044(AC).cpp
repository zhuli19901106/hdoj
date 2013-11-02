#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

__int64 a[50];
int x, y;

int main()
{
    int i;
    int t, ti;

    a[0] = 1;
    a[1] = 1;
    for(i = 2; i < 50; ++i){
        a[i] = a[i - 1] + a[i - 2];
    }

    while(scanf("%d", &t) == 1){
        for(ti = 0; ti < t; ++ti){
            scanf("%d%d", &x, &y);
            printf("%I64d\n", a[y - x]);
        }
    }

    return 0;
}

