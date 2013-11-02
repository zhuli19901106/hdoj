#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAXN = 250;
int n;
int f[1001][MAXN];

int main()
{
    int i, j;
    int t, ti;

    memset(f, 0, 1001 * MAXN * sizeof(int));
    f[1][0] = 1;
    f[2][0] = 1;
    for(i = 3; i <= 1000; ++i){
        for(j = 0; j < MAXN; ++j){
            f[i][j] = f[i - 1][j] + f[i - 2][j];
        }
        for(j = 0; j < MAXN - 1; ++j){
            f[i][j + 1] += f[i][j] / 10;
            f[i][j] %= 10;
        }
        f[i][MAXN - 1] %= 10;
    }

    while(scanf("%d", &t) == 1){
        for(ti = 0; ti < t; ++ti){
            scanf("%d", &i);
            j = MAXN - 1;
            while(j > 0 && f[i][j] == 0){
                --j;
            }
            while(j >= 0){
                printf("%d", f[i][j]);
                --j;
            }
            printf("\n");
        }
    }

    return 0;
}

