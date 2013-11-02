#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

__int64 n, res;

__int64 f(__int64 n)
{
    return n * (n + 1) * (2 * n + 1) / 6;
}

int main()
{
    while(scanf("%I64d", &n) == 1){
        printf("%I64d\n", f(n + 1) - 4 * f((n + 1) / 2));
    }

    return 0;
}

