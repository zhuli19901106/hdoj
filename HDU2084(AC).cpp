#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

const int MAXN = 105;
int a[MAXN][MAXN];
int f[MAXN][MAXN];
int n;
int res;

int main()
{
    int i, j;
    int t, ti;

    while(scanf("%d", &t) == 1){
        for(ti = 0; ti < t; ++ti){
            scanf("%d", &n);
            for(i = 0; i < n; ++i){
                for(j = 0; j <= i; ++j){
                    scanf("%d", &a[i][j]);
                }
            }
            f[0][0] = a[0][0];
            for(i = 1; i < n; ++i){
                f[i][0] = f[i - 1][0] + a[i][0];
                for(j = 1; j < i; ++j){
                    if(f[i - 1][j - 1] < f[i - 1][j]){
                        f[i][j] = f[i - 1][j] + a[i][j];
                    }else{
                        f[i][j] = f[i - 1][j - 1] + a[i][j];
                    }
                }
                f[i][i] = f[i - 1][i - 1] + a[i][i];
            }

            res = f[n - 1][0];
            for(i = 1; i < n; ++i){
                if(f[n - 1][i] > res){
                    res = f[n - 1][i];
                }
            }

            printf("%d\n", res);
        }
    }

    return 0;
}

