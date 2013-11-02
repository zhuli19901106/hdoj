#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;

int f[1001];
int n, m;
int a[55];
int b[55];
int ub[55];
int res;

int main()
{
    int i, j;
    int tmp;
    int ti;

    ti = 0;
    while(scanf("%d%d", &m, &n) == 2 && (m || n)){
        ++ti;
        memset(f, 0, 1001 * sizeof(int));
        for(i = 0; i < n; ++i){
            scanf("%d", &tmp);
            a[i] = tmp;
            f[tmp] = 1;
        }

        j = 0;
        for(i = n * m; i >= 1; --i){
            if(!f[i]){
                f[i] = 1;
                b[j++] = i;
                if(j == n){
                    break;
                }
            }
        }

        sort(a, a + n);
        sort(b, b + n);

        res = n;
        memset(ub, 0, 55 * sizeof(int));
        for(i = n - 1; i >= 0; --i){
            for(j = 0; j < n; ++j){
                if(!ub[j] && b[j] > a[i]){
                    ub[j] = 1;
                    --res;
                    break;
                }
            }
        }

        printf("Case %d: %d\n", ti, res);
    }

    return 0;
}

