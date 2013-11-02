#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

__int64 a[9][41];
__int64 res;
int f[9];
int n;

int main()
{
    int t, ti;
    int i, j, k;
    int x, y;

    while(scanf("%d", &t) == 1){
        for(ti = 0; ti < t; ++ti){
            memset(a, 0, 9 * 41 * sizeof(__int64));
            memset(f, 0, 9 * sizeof(int));
            scanf("%d%d", &n, &k);
            for(i = 1; i <= k; ++i){
                scanf("%d%d", &x, &y);
                f[x] = y;
            }

            for(i = 0; i <= 8; ++i){
                a[i][0] = 1;
            }
            for(i = 1; i <= 8; ++i){
                for(j = 1; j <= 40; ++j){
                    a[i][j] = a[i - 1][j];
                    for(k = 1; k <= f[i]; ++k){
                        if(j - k * i >= 0){
                            a[i][j] += a[i - 1][j - k * i];
                        }
                    }
                }
            }

            printf("%I64d\n", a[8][n]);
        }
    }

    return 0;
}

