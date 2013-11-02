#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

int main()
{
    int i;
    int n;

    while(1)
    {
        scanf("%d", &n);
        if(n == 0)
        {
            break;
        }

        i = 1;
        while((n & i) == 0)
        {
            i = i * 2;
        }

        printf("%d\n", i);
    }

    return 0;
}

