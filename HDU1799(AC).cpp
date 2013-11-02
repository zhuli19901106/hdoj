#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int mod = 1007;
int f[2001][2001];

int main()
{
    int i, j;
    int t, ti;
    int n, m;

    memset(f, 0, 2001 * 2001 * sizeof(int));

    f[1][0] = 1;
    f[1][1] = 1;
    for(i = 2; i <= 2000; ++i){
        for(j = 0; j <= i; ++j){
            f[i][j] = (f[i - 1][j - 1] + f[i - 1][j]) % mod;
        }
    }

    while(scanf("%d", &t) == 1){
        for(ti = 0; ti < t; ++ti){
            scanf("%d%d", &m, &n);
            printf("%d\n", f[n][m]);
        }
    }
    
    return 0;
}

