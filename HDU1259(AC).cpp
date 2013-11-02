#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

int main()
{
    int i, m;
    int n, ni;
    int a[8];
    int x, y, t;

    while(scanf("%d", &n) == 1){
        for(ni = 0; ni < n; ++ni){
            scanf("%d", &m);
            for(i = 1; i <= 7; ++i){
                a[i] = i;
            }
            
            for(i = 1; i <= m; ++i){
                scanf("%d%d", &x, &y);
                t = a[x];
                a[x] = a[y];
                a[y] = t;
            }

            for(i = 1; i <= 7; ++i){
                if(a[i] == 2){
                    printf("%d\n", i);
                    break;
                }
            }
        }
    }

    return 0;
}

