#define _CRT_SECURE_NO_WARNINGS
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;

int isprime(int n)
{
    int i;
    double rt;

    if(n < 1)
    {
        return 0;
    }
    else if(n == 1)
    {
        return 1;
    }
    else if(n == 2)
    {
        return 1;
    }
    else
    {
        rt = sqrt(1.0 * n);
        for(i = 2; i <=rt; i++)
        {
            if(n % i == 0)
            {
                return 0;
            }
        }

        return 1;
    }
}

int main()
{
    int i;
    int primecount;
    int c;
    int n;
    int primes[400];
    int isprimes[1001];
    int indices[1001];
    int leftprime;
    int rightprime;
    int leftindex;
    int rightindex;
    int leftbound;
    int rightbound;

    memset(primes, 0, 400 * sizeof(int));
    memset(indices, 0, 1001 * sizeof(int));
    memset(isprimes, 0, 1001 * sizeof(int));

    primecount = 0;
    for(i = 0; i <= 1000; i++)
    {
        isprimes[i] = isprime(i);
        if(isprimes[i] != 0)
        {
            primes[primecount] = i;
            indices[i] = primecount;
            primecount++;
        }
    }

    while(1)
    {
        if(scanf("%d%d", &n, &c) != 2)
        {
            break;
        }

        leftprime = 1;
        rightprime = n;
        while(isprimes[rightprime] == 0)
        {
            rightprime--;
        }
        leftindex = 0;
        rightindex = indices[rightprime];

        if((rightindex - leftindex + 1) % 2 == 1)
        {
            leftbound = (leftindex + rightindex) / 2 - c + 1;
            rightbound = (leftindex + rightindex) / 2 + c - 1;
            if(leftbound < leftindex)
            {
                leftbound = leftindex;
            }
            if(rightbound > rightindex)
            {
                rightbound = rightindex;
            }
        }
        else
        {
            leftbound = (leftindex + rightindex + 1) / 2 - c;
            rightbound = (leftindex + rightindex - 1) / 2 + c;
            if(leftbound < leftindex)
            {
                leftbound = leftindex;
            }
            if(rightbound > rightindex)
            {
                rightbound = rightindex;
            }
        }

        printf("%d %d:", n, c);
        for(i = leftbound; i <= rightbound; i++)
        {
            printf(" %d", primes[i]);
        }
        printf("\n\n");
    }

    return 0;
}

