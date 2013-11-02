#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
    int a, b;

    while(scanf("%d%d", &a, &b) == 2){
        printf("%d %d\n", a * b - a - b, (a - 1) * (b - 1) / 2);
    }

    return 0;
}

