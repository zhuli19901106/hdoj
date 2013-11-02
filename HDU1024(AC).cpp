#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

__int64 f[2][1000005];
__int64 a[1000005];
int m, n;

__int64 mymax(__int64 a, __int64 b)
{
    return a > b ? a : b;
}

int main()
{
    int i, j;
    int flag;
    __int64 maxv;

    while(scanf("%d%d", &m, &n) == 2){
        for(i = 1; i <= n; ++i){
            f[0][i] = f[1][i] = 0;
        }

        for(i = 1; i <= n; ++i){
            scanf("%I64d", &a[i]);
        }

        flag = 0;
        for(i = 1; i <= m; ++i){
            f[flag][i] = f[1 - flag][i - 1] + a[i];

            maxv = f[1 - flag][i - 1];
            for(j = i + 1; j <= n - m + i; ++j){
                maxv = mymax(maxv, f[1 - flag][j - 1]);
                f[flag][j] = mymax(f[flag][j - 1], maxv) + a[j];
            }
            flag = 1 - flag;
        }
        flag = 1 - flag;

        maxv = f[flag][m];
        for(i = m + 1; i <= n; ++i){
            if(f[flag][i] > maxv){
                maxv = f[flag][i];
            }
        }

        printf("%I64d\n", maxv);
    }

    return 0;
}

