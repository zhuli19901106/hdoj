#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
    int i, n;
    int res;

    while(scanf("%d", &n) == 1 && n){
        res = 1;
        for(i = 0; i < n; ++i){
            res = (res * n) % 9;
        }
        if(!res){
            res = 9;
        }
        printf("%d\n", res);
    }

    return 0;
}

