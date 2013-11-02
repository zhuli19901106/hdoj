#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

__int64 a[1005];
__int64 f[1005];
__int64 res;
int n;

int main()
{
    int i, j;

    while(scanf("%d", &n) == 1 && n){
        for(i = 0; i < n; ++i){
            scanf("%I64d", &a[i]);
        }
        f[0] = a[0];
        for(i = 1; i < n; ++i){
            f[i] = a[i];
            for(j = 0; j < i; ++j){
                if(a[j] < a[i] && f[j] + a[i] > f[i]){
                    f[i] = f[j] + a[i];
                }
            }
        }
        
        res = f[0];
        for(i = 1; i < n; ++i){
            if(f[i] > res){
                res = f[i];
            }
        }

        printf("%I64d\n", res);
    }

    return 0;
}

