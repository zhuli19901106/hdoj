#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

int main()
{
    int a, b;

    while(scanf("%d%d", &a, &b) == 2 && (a || b)){
        printf("%d\n", a + b);
    }

    return 0;
}

