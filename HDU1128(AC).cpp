#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int getsum(int n)
{
    int dsum;
    int n0;

    n0 = n;
    dsum = 0;
    while(n > 0)
    {
        dsum += n % 10;
        n = n / 10;
    }

    return n0 + dsum;
}

int main()
{
    int *a;
    int i;
    int sum;

    a = (int *)malloc(1000001 * sizeof(int));

    memset(a, 0, 1000001 * sizeof(int));

    for(i = 1; i < 1000001; i++)
    {
        sum = getsum(i);
        if(sum < 1000001)
        {
            a[sum] = 1;
        }
    }

    for(i = 1; i < 1000001; i++)
    {
        if(a[i] == 0)
        {
            printf("%d\n", i);
        }
    }

    free(a);
    return 0;
}

