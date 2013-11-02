#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

int main()
{
    long sum;
    long dif;
    long large;
    long small;
    long n;
    long i;

    scanf("%ld", &n);
    for(i = 0; i < n; i++)
    {
        scanf("%ld%ld", &sum, &dif);
        large = (sum + dif) / 2;
        small = (sum - dif) / 2;

        if((sum + dif) % 2 == 1)
        {
            printf("impossible\n");
        }
        else if(large < small)
        {
            printf("impossible\n");
        }
        else if(large < 0 || small < 0)
        {
            printf("impossible\n");
        }
        else
        {
            printf("%ld %ld\n", large, small);
        }
    }

    return 0;
}

