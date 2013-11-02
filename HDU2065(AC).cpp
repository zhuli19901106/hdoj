#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int f1[4], f2[4];
unsigned __int64 n;
int op[4][4] = {
    {2, 1, 1, 0},
    {1, 2, 0, 1},
    {1, 0, 2, 1},
    {0, 1, 1, 2}
};
int res[4][4];

void mat_pow(int res[][4], int mat[][4], unsigned __int64 n)
{
    int p[4][4];
    int i, j, k;

    if(n == 0){
        for(i = 0; i < 4; ++i){
            for(j = 0; j < 4; ++j){
                res[i][j] = (i == j);
            }
        }
    }else if(n == 1){
        for(i = 0; i < 4; ++i){
            for(j = 0; j < 4; ++j){
                res[i][j] = mat[i][j];
            }
        }
        return;
    }else{
        if(n % 2){
            mat_pow(p, mat, n / 2);
            for(i = 0; i < 4; ++i){
                for(j = 0; j < 4; ++j){
                    res[i][j] = 0;
                    for(k = 0; k < 4; ++k){
                        res[i][j] += (p[i][k] * p[k][j] % 100);
                    }
                    res[i][j] %= 100;
                }
            }
            for(i = 0; i < 4; ++i){
                for(j = 0; j < 4; ++j){
                    p[i][j] = res[i][j];
                }
            }
            for(i = 0; i < 4; ++i){
                for(j = 0; j < 4; ++j){
                    res[i][j] = 0;
                    for(k = 0; k < 4; ++k){
                        res[i][j] += (p[i][k] * mat[k][j] % 100);
                    }
                    res[i][j] %= 100;
                }
            }
        }else{
            mat_pow(p, mat, n / 2);
            for(i = 0; i < 4; ++i){
                for(j = 0; j < 4; ++j){
                    res[i][j] = 0;
                    for(k = 0; k < 4; ++k){
                        res[i][j] += (p[i][k] * p[k][j] % 100);
                    }
                    res[i][j] %= 100;
                }
            }
        }
    }
}

int main()
{
    int t, ti;
    int i, j;

    while(scanf("%d", &t) == 1 && t){
        for(ti = 1; ti <= t; ++ti){
            scanf("%I64u", &n);
            printf("Case %d: ", ti);
            f1[0] = 2;
            f1[1] = 1;
            f1[2] = 1;
            f1[3] = 0;
            mat_pow(res, op, n - 1);
            for(i = 0; i < 4; ++i){
                f2[i] = 0;
                for(j = 0; j < 4; ++j){
                    f2[i] += res[i][j] * f1[j];
                }
                f2[i] %= 100;
            }
            printf("%d\n", f2[0]);
        }
        printf("\n");
    }

    return 0;
}

