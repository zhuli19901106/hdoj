#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

int main()
{
    int a, b;
    int n;
    int t;

    while(scanf("%d", &t) == 1){
        while(t--){
            scanf("%d", &n);
            a = 0;
            while(n--){
                scanf("%d", &b);
                a += b;
            }
            printf("%d\n", a);
        }
    }

    return 0;
}

