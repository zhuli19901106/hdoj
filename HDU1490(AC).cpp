#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int a[1005][1005];
int n;

int main()
{
    int i, j;
    bool suc;

    while(scanf("%d", &n) == 1 && n){
        memset(a, 0, 1005 * 1005 * sizeof(int));
        suc = true;

        for(i = 0; i < n; ++i){
            for(j = 0; j < n; ++j){
                scanf("%d", &a[i][j]);
            }
        }

        for(i = 0; i < n - 1; ++i){
            for(j = 0; j < n - 1; ++j){
                if(a[i][j] + a[i + 1][j + 1] != a[i + 1][j] + a[i][j + 1]){
                    suc = false;
                }
                if(!suc){
                    break;
                }
            }
            if(!suc){
                break;
            }
        }

        if(suc){
            printf("homogeneous\n");
        }else{
            printf("not homogeneous\n");
        }
    }

    return 0;
}

