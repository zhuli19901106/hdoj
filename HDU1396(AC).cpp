#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

int main()
{
    int i;
    int n;
    int a[1000];

    a[0] = 0;
    a[1] = 1;
    for(i = 2; i <= 500; i++)
    {
        if(i % 2 == 1)
        {
            a[i] = a[i - 1] + (i + 1) * (i - 1) / 4 + (i + 1) * i / 2;
        }
        else
        {
            a[i] = a[i - 1] + i * i / 4 + (i + 1) * i / 2;
        }
    }

    while(1)
    {
        if(scanf("%d", &n) != 1)
        {
            break;
        }

        printf("%d\n", a[n]);
    }

    return 0;
}

