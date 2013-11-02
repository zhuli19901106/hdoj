#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int a[11][11];
int n, cc;

int main()
{
    int i, j;

    while(scanf("%d", &n) == 1){
        memset(a, 0, 11 * 11 * sizeof(int));
        cc = 1;
        for(i = 1; i <= n; ++i){
            a[1][i] = cc;
            ++cc;
        }
        for(i = 2; i <= n; ++i){
            a[i][n] = cc;
            ++cc;
        }
        for(i = n - 1; i >= 1; --i){
            a[n][i] = cc;
            ++cc;
        }
        for(i = n - 1; i >= 2; --i){
            a[i][1] = cc;
            ++cc;
        }

        for(i = 1; i <= n; ++i){
            for(j = 1; j <= n; ++j){
                if(a[i][j]){
                    printf("%3d", a[i][j]);
                }else{
                    printf("   ");
                }
            }
            printf("\n");
        }
    }

    return 0;
}

