#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int n;

int gcd(int a, int b)
{
    return a ? gcd(b % a, a) : b;
}

int lcm(int a, int b)
{
    return a / gcd(a, b) * b;
}

int main()
{
    int tmp, i, res;

    while(scanf("%d", &n) == 1){
        res = 1;
        for(i = 0; i < n; ++i){
            scanf("%d", &tmp);
            res = lcm(res, tmp);
        }

        printf("%d\n", res);
    }

    return 0;
}

