#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

int main()
{
    int n;
    int u;
    int d;
    int minute;

    while(1)
    {
        scanf("%d%d%d", &n, &u, &d);
        if(n == 0 && u == 0 && d == 0)
        {
            break;
        }

        minute = 0;
        while(1)
        {
            n = n - u;
            minute++;
            if(n <= 0)
            {
                break;
            }

            n = n + d;
            minute++;
        }
        printf("%d\n", minute);
    }

    return 0;
}

