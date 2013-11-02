#define _CRT_SECURE_NO_WARNINGS
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int n;
int a[30];
int b[30];
int res[30];
int ps[30];
int tot;

void dfs(int sum, int index)
{
    if(index == n){
        int i;

        if(sum <= tot - sum){
            return;
        }
        for(i = 0; i < n; ++i){
            if(b[i] && sum - a[i] <= tot - sum + a[i]){
                ++res[i];
            }
        }
    }else{
        if(sum + ps[index] <= tot - (sum + ps[index])){
            return;
        }
        b[index] = 0;
        dfs(sum, index + 1);

        b[index] = 1;
        dfs(sum + a[index], index + 1);
        b[index] = 0;
    }
}

int main()
{
    int i;
    int t, ti;

    while(scanf("%d", &t) == 1){
        for(ti = 0; ti < t; ++ti){
            scanf("%d", &n);
            tot = 0;
            for(i = 0; i < n; ++i){
                scanf("%d", &a[i]);
                tot += a[i];
            }
            memset(ps, 0, 30 * sizeof(int));
            ps[n - 1] = a[n - 1];
            for(i = n - 2; i >= 0; --i){
                ps[i] = ps[i + 1] + a[i];
            }
            memset(b, 0, 30 * sizeof(int));
            memset(res, 0, 30 * sizeof(int));
            dfs(0, 0);
            for(i = 0; i < n; ++i){
                printf((i ? " %d" : "%d"), res[i]);
            }
            printf("\n");
        }
    }

    return 0;
}

