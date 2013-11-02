#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

__int64 a[31];
int n;

int main()
{
    int i;

    a[0] = 1;
    for(i = 1; i <= 30; ++i){
        a[i] = 2 * (a[i - 1] + 1);
    }

    while(scanf("%d", &n) == 1){
        printf("%I64d\n", a[n - 1]);
    }

    return 0;
}

