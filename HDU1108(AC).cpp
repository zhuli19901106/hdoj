#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

int gcd(int a, int b)
{
    return a ? gcd(b % a, a) : b;
}

int main()
{
    int a, b;

    while(scanf("%d%d", &a, &b) == 2){
        printf("%d\n", a * b / gcd(a, b));
    }

    return 0;
}

