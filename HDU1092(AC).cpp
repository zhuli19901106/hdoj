#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

int main()
{
    int n, a, b;

    while(scanf("%d", &n) == 1 && n){
        a = 0;
        while(n--){
            scanf("%d", &b);
            a += b;
        }
        printf("%d\n", a);
    }

    return 0;
}

