#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
    int a[31];
    int i;
    int n;

    a[0] = 0;
    for(i = 1; i <= 30; ++i){
        a[i] = 2 * a[i - 1] + 1;
    }

    while(scanf("%d", &n) == 1){
        while(n--){
            scanf("%d", &i);
            printf("%d\n", a[i]);
        }
    }

    return  0;
}

