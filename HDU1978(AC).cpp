#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAXN = 105;
const int MOD = 10000;
int f[MAXN][MAXN];
int a[MAXN][MAXN];
int n, m;

int main()
{
    int i, j;
    int x, y, r;
    int t, ti;

    while(scanf("%d", &t) == 1){
        for(ti = 0; ti < t; ++ti){
            scanf("%d%d", &n, &m);
            for(i = 1; i <= n; ++i){
                for(j = 1; j <= m; ++j){
                    scanf("%d", &a[i][j]);
                }
            }

            memset(f, 0, MAXN * MAXN * sizeof(int));
            f[1][1] = 1;
            for(i = 1; i <= n; ++i){
                for(j = 1; j <= m; ++j){
                    for(r = 1; r <=    a[i][j]; ++r){
                        for(x = i; x <= i + j + r - j; ++x){
                            y = i + j + r - x;
                            if(x >= 1 && x <= n && y >= 1 && y <= m){
                                f[x][y] = (f[x][y] + f[i][j]) % MOD;
                            }
                        }
                    }
                }
            }

            printf("%d\n", f[n][m]);
        }
    }

    return 0;
}

