#define _CRT_SECURE_NO_WARNINGS
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int n, s;
int res, tmp;

int main()
{
    int i;

    while(scanf("%d%d", &n, &s) == 2){
        scanf("%d", &res);
        for(i = 1; i < n; ++i){
            scanf("%d", &tmp);
            if(tmp < res){
                res = tmp;
            }
        }
        printf("%d\n", s / res);
    }

    return 0;
}

