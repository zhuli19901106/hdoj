#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int MAXN = 105;
__int64 f[MAXN][MAXN];
int n, p, m, t;

int main()
{
    int i, j;

    while(scanf("%d%d%d%d", &n, &p, &m, &t) == 4){
        memset(f, 0, MAXN * MAXN * sizeof(__int64));
        f[0][p] = 1;
        for(i = 1; i <= m; ++i){
            for(j = 1; j <= n; ++j){
                f[i][j] = f[i - 1][j - 1] + f[i - 1][j + 1];
            }
        }

        printf("%I64d\n", f[m][t]);
    }

    return 0;
}

