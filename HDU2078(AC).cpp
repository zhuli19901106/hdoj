#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int n;
int tmp, res;

int main()
{
    int t, ti;
    int i;

    while(scanf("%d", &t) == 1){
        for(ti = 0; ti < t; ++ti){
            scanf("%d%d", &n, &tmp);
            scanf("%d", &res);
            for(i = 1; i < n; ++i){
                scanf("%d", &tmp);
                if(tmp < res){
                    res = tmp;
                }
            }
            printf("%d\n", (100 - res) * (100 - res));
        }
    }

    return 0;
}

