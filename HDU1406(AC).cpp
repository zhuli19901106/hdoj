#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAXN = 10000;
int a[MAXN];
int b[MAXN];

int main()
{
    int i, j, tmp;
    int t, ti;

    memset(a, 0, MAXN * sizeof(int));
    a[0] = 0;
    a[1] = 1;
    for(i = 2; i < MAXN; ++i){
        a[i] = 0;
        for(j = 1; j * j <= i; ++j){
            if(i % j == 0){
                a[i] += j;
                if(j != i / j){
                    a[i] += i / j;
                }
            }
        }
    }

    memset(b, 0, MAXN * sizeof(int));
    for(i = 2; i < MAXN; ++i){
        b[i] = (a[i] == 2 * i ? b[i - 1] + 1 : b[i - 1]);
    }

    while(scanf("%d", &t) == 1){
        for(ti = 0; ti < t; ++ti){
            scanf("%d%d", &i, &j);
            if(i > j){
                tmp = i;
                i = j;
                j = tmp;
            }
            printf("%d\n", b[j] - b[i - 1]);
        }
    }

    return 0;
}

