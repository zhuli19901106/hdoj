#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

long gcd(long a, long b)
{
    long lgcd;

    if(a > b)
    {
        return gcd(b, a);
    }
    else if(b % a == 0)
    {
        return a;
    }

    while(1)
    {
        if(a > b)
        {
            if(a % b == 0)
            {
                return b;
            }
            else
            {
                a = a % b;
            }
        }
        else if(b > a)
        {
            if(b % a == 0)
            {
                return a; 
            }
            else
            {
                b = b % a;
            }
        }
    }
}

long lcm(long a, long b)
{
    long lgcd;

    lgcd = gcd(a, b);

    return a / lgcd * b;
}

int main()
{
    long a;
    long llcm;
    long t;
    long n;
    long i;
    long j;

    scanf("%ld", &t);
    for(i = 0; i < t; i++)
    {
        scanf("%ld", &n);
        scanf("%ld", &llcm);
        for(j = 1; j < n; j++)
        {
            scanf("%ld", &a);
            llcm = lcm(llcm, a);
        }

        printf("%ld\n", llcm);
    }

    return 0;
}

