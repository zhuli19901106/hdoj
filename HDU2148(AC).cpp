#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;

__int64 a[3];

int main()
{
    int n, id;
    int res;
    int i;
    int t, ti;
    int a[1005];

    while(scanf("%d", &t) == 1){
        for(ti = 0; ti < t; ++ti){
            scanf("%d%d", &n, &id);
            for(i = 1; i <= n; ++i){
                scanf("%d", &a[i]);
            }
            res = 0;
            for(i = 1; i <= n; ++i){
                if(a[i] > a[id]){
                    ++res;
                }
            }
            printf("%d\n", res);
        }
    }

    return 0;
}

