#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

int main()
{
    int i;
    int n;
    int x;
    int y;

    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        scanf("%d%d", &x, &y);
        if(x == y)
        {
            if(x % 2 == 1)
            {
                printf("%d\n", x + y - 1);
            }
            else
            {
                printf("%d\n", x + y);
            }
        }
        else if(x - y == 2)
        {
            if(x % 2 == 1)
            {
                printf("%d\n", x + y - 1);
            }
            else
            {
                printf("%d\n", x + y);
            }
        }
        else
        {
            printf("No Number\n");
        }
    }

    return 0;
}

