#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAXV = 50 * 50 * 100 / 2 + 10;
int f[2][MAXV];
int sum, tot;
const int MAXN = 50;
int v[MAXN];
int c[MAXN];
int n;

int main()
{
    int i, j, k;
    int f1;

    while(scanf("%d", &n) == 1 && n > 0){
        sum = 0;
        for(i = 0; i < n; ++i){
            scanf("%d%d", &v[i], &c[i]);
            sum += v[i] * c[i];
        }
        tot = sum;
        sum /= 2;
        memset(f, 0, 2 * MAXV * sizeof(int));
        f[0][0] = 1;
        for(i = 0; i < n; ++i){
            memset(f[1], 0, MAXV * sizeof(int));
            for(j = c[i]; j >= 0; --j){
                for(k = sum; k >= j * v[i]; --k){
                    f[1][k] = f[1][k] | f[0][k - j * v[i]];
                }
            }
            memcpy(f[0], f[1], MAXV * sizeof(int));
        }

        i = sum;
        while(i >= 0 && f[0][i] == 0){
            --i;
        }
        if(i >= 0){
            printf("%d %d\n", tot - i, i);
        }
    }

    return 0;
}

