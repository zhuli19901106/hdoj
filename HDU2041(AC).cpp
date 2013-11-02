#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

__int64 a[41];

int main()
{
    int i;
    int n, ni;

    a[0] = 0;
    a[1] = 1;
    for(i = 2; i <= 40; ++i){
        a[i] = a[i - 1] + a[i - 2];
    }

    while(scanf("%d", &n) == 1){
        for(ni = 0; ni < n; ++ni){
            scanf("%d", &i);
            printf("%I64d\n", a[i]);
        }
    }
    
    return 0;
}

