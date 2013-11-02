#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

__int64 res[51];
int n;

int main()
{
    res[1] = 3;
    res[2] = 6;
    res[3] = 6;
    for(n = 4; n <= 50; ++n){
        res[n] = 2 * res[n - 2] + res[n - 1];
    }
    
    while(scanf("%d", &n) == 1){
        printf("%I64d\n", res[n]);
    }

    return 0;
}

