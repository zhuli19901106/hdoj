#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int n, m, c;
int a[205][2050];
int f[205][2050];
int d[4][2] = {
    {1, 0}, {0, 1}, {1, 2}, {2, 1}
};

inline bool inbound(int x, int y, int n, int m)
{
    if(x >= 1 && x <= n){
        if(y >= 1 && y <= 1 + (x - 1) * m){
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }
}

int main()
{
    int i, j, k;
    int x, y;
    int res;

    while(scanf("%d%d%d", &n, &m, &c) == 3){
        memset(a, 0, 205 * 2050 * sizeof(int));
        memset(f, 0, 205 * 2050 * sizeof(int));
        for(i = 1; i <= n; ++i){
            for(j = 1; j <= 1 + (i - 1) * m; ++j){
                scanf("%d", &a[i][j]);
            }
        }
        f[1][1] = a[1][1];
        for(i = 1; i <= n; ++i){
            for(j = 1; j <= 1 + (i - 1) * m; ++j){
                if(f[i][j] == 0){
                    continue;
                }
                for(k = 0; k < 4; ++k){
                    x = i + d[k][0];
                    y = j + d[k][1];
                    if(inbound(x, y, n, m) && f[i][j] > c && f[i][j] - c + a[x][y] > f[x][y]){
                        f[x][y] = f[i][j] - c + a[x][y];
                    }
                }
            }
        }

        for(i = 1; i <= 1 + (n - 1) * m; ++i){
            if(f[n][i] > 0){
                break;
            }
        }
        if(i > 1 + (n - 1) * m){
            printf("what a pity mouse!!\n");
        }else{
            for(res = f[n][i], ++i; i <= 1 + (n - 1) * m; ++i){
                if(f[n][i] > 0 && f[n][i] < res){
                    res = f[n][i];
                }
            }
            printf("%d\n", res);
        }
    }

    return 0;
}

