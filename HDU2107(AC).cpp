#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int n, res, tmp;

int main()
{
    int i;

    while(scanf("%d", &n) == 1 && n){
        scanf("%d", &res);
        for(i = 1; i < n; ++i){
            scanf("%d", &tmp);
            if(tmp > res){
                res = tmp;
            }
        }

        printf("%d\n", res);
    }

    return 0;
}

