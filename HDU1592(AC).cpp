#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAXN = 350;
int n;
int f[1001][MAXN];

int main()
{
    int i, j;

    memset(f, 0, 1001 * MAXN * sizeof(int));
    f[0][0] = 1;
    for(i = 1; i <= 1000; ++i){
        for(j = 0; j < MAXN; ++j){
            f[i][j] = 2 * f[i - 1][j];
        }
        ++f[i][0];
        for(j = 0; j < MAXN - 1; ++j){
            f[i][j + 1] += (f[i][j] / 10);
            f[i][j] %= 10;
        }
        f[i][MAXN - 1] %= 10;
    }

    while(scanf("%d", &n) == 1){
        i = MAXN - 1;
        while(i > 0 && f[n][i] == 0){
            --i;
        }
        while(i >= 0){
            printf("%d", f[n][i]);
            --i;
        }
        printf("\n");
    }

    return 0;
}

