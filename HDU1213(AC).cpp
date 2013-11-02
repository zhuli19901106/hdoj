#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAXN = 1005;
int n, m;
int a[MAXN];
int b[MAXN];
int res;

int find_root(int x)
{
    int r, k;

    r = x;
    while(r != a[r]){
        r = a[r];
    }

    k = x;
    while(x != r){
        x = a[x];
        a[k] = r;
        k = x;
    }

    return r;
}

int main()
{
    int t, ti;
    int x, y;
    int rx, ry;
    int i;

    while(scanf("%d", &t) == 1){
        for(ti = 0; ti < t; ++ti){
            scanf("%d%d", &n, &m);
            for(i = 1; i <= n; ++i){
                a[i] = i;
            }
            for(i = 1; i <= m; ++i){
                scanf("%d%d", &x, &y);
                rx =find_root(x);
                ry = find_root(y);
                if(rx != ry){
                    a[rx] = ry;
                    find_root(x);
                    find_root(y);
                }
            }

            for(i = 1; i <= n; ++i){
                find_root(i);
            }
            
            res = 0;
            memset(b, 0, MAXN * sizeof(int));
            for(i = 1; i <= n; ++i){
                if(!b[a[i]]){
                    ++res;
                    b[a[i]] = 1;
                }
            }

            printf("%d\n", res);
        }
    }

    return 0;
}

