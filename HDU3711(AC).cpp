#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

int f(long a, long b)
{
    long r;
    long bit;
    long count;

    count = 0;
    bit = 1;
    r = a ^ b;
    while(bit <= r)
    {
        if((bit & r) != 0)
        {
            count++;
        }
        bit = bit * 2;
    }

    return count;
}

int main()
{
    int t;
    int i;
    int j;
    int k;
    int m;
    int n;
    long a[100];
    long b[100];
    int result[100];
    int minindex;

    scanf("%d", &t);
    for(i = 0; i < t; i++)
    {
        scanf("%d%d", &m, &n);

        for(j = 0; j < m; j++)
        {
            scanf("%ld", &a[j]);
        }

        for(j = 0; j < n; j++)
        {
            scanf("%ld", &b[j]);
        }

        for(j = 0; j < n; j++)
        {
            for(k = 0; k < m; k++)
            {
                result[k] = f(a[k], b[j]);
            }

            minindex = 0;
            for(k = 1; k < m; k++)
            {
                if(result[k] < result[minindex])
                {
                    minindex = k;
                }
                else if(result[k] == result[minindex])
                {
                    if(a[k] < a[minindex])
                    {
                        minindex = k;
                    }
                }
            }

            printf("%ld\n", a[minindex]);
        }
    }

    return 0;
}

