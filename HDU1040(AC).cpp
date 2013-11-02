#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;

int a[1005], n;

int main()
{
    int t, ti;
    int i;

    while(scanf("%d", &t) == 1){
        for(ti = 0; ti < t; ++ti){
            scanf("%d", &n);
            for(i = 0; i < n; ++i){
                scanf("%d", &a[i]);
            }
            sort(a, a + n);
            for(i = 0; i < n; ++i){
                printf((i ? " %d" : "%d"), a[i]);
            }
            printf("\n");
        }
    }

    return 0;
}

