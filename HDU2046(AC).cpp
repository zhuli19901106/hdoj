#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

__int64 a[51];
int main()
{
    int i;

    a[0] = 1;
    a[1] = 1;
    for(i = 2; i <= 50; ++i){
        a[i] = a[i - 1] + a[i - 2];
    }
    
    while(scanf("%d", &i) == 1){
        printf("%I64d\n", a[i]);
    }

    return 0;
}

