#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

__int64 a[27][51];
__int64 res;
int f[27];

int main()
{
    int t, ti;
    int i, j, k;

    while(scanf("%d", &t) == 1){
        for(ti = 0; ti < t; ++ti){
            memset(a, 0, 51 * 27 * sizeof(__int64));
            for(i = 1; i <= 26; ++i){
                scanf("%d", &f[i]);
            }

            for(i = 0; i <= 26; ++i){
                a[i][0] = 1;
            }
            for(i = 1; i <= 26; ++i){
                for(j = 1; j <= 50; ++j){
                    a[i][j] = a[i - 1][j];
                    for(k = 1; k <= f[i]; ++k){
                        if(j - k * i >= 0){
                            a[i][j] += a[i - 1][j - k * i];
                        }
                    }
                }
            }

            res = 0;
            for(i = 1; i <= 50; ++i){
                res += a[26][i];
            }

            printf("%I64d\n", res);
        }
    }

    return 0;
}

