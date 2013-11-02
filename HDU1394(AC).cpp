#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

long getinv(long a[], long n)
{
    long i;
    long j;
    long inv;

    inv = 0;
    for(i = 2; i <= n; i ++)
    {
        for(j = 1; j < i; j++)
        {
            if(a[j] > a[i])
            {
                inv++;
            }
        }
    }

    return inv;
}

int main()
{
    long i;
    long j;
    long n;
    long a[10001];
    long *p;
    long mininv;
    long inv;
    long large;
    long small;

    while(1)
    {
        if(scanf("%ld", &n) != 1)
        {
            break;
        }

        for(i = 1; i <= n; i++)
        {
            scanf("%ld", &a[i]);
        }
        p = a;

        mininv = getinv(a, n);
        inv = mininv;
        for(i = 1; i < n; i++)
        {
            large = 0;
            small = 0;
            for(j = 2; j <= n; j++)
            {
                if(p[j] < p[1])
                {
                    small++;
                }
                else if(p[j] > p[1])
                {
                    large++;
                }
            }
            p[n + 1] = p[1];
            p++;

            inv = inv - small + large;
            if(inv < mininv)
            {
                mininv = inv;
            }
        }

        printf("%ld\n", mininv);
    }

    return 0;
}

