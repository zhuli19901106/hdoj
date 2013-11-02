#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAXN = 2001;
int a[MAXN];
int b[MAXN];

int myabs(int a)
{
    return (a >= 0 ? a : -a);
}

int main()
{
    int t, ti;
    int n, k;
    int i, j;

    while(scanf("%d", &t) == 1){
        for(ti = 0; ti < t; ++ti){
            memset(b, 0, MAXN * sizeof(int));
            scanf("%d%d", &n, &k);
            for(i = 0; i < n; ++i){
                scanf("%d", &a[i]);
            }

            for(i = 0; i < n; ++i){
                for(j = 0; j < i; ++j){
                    b[myabs(a[i] - a[j])] = 1;
                }
            }

            j = 0;
            for(i = 0; i <= 2000; ++i){
                if(b[i]){
                    ++j;
                }
                if(j == k){
                  break;
                }
            }
            printf("%d\n", i);
        }
    }

    return 0;
}

