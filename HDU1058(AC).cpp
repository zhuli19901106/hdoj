#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int min(int a, int b)
{
    return (a > b ? b : a);
}

int main()
{
    int a[10000];
    int c2, c3, c5, c7;
    int a2, a3, a5, a7;
    int amin;
    int c;
    int n;

    c = 0;
    a[c] = 1;
    c2 = c3 = c5 = c7 = 0;
    while(c < 5842)
    {
        a2 = a[c2] * 2;
        a3 = a[c3] * 3;
        a5 = a[c5] * 5;
        a7 = a[c7] * 7;

        amin = min(min(a2, a3), min(a5, a7));
        a[++c] = amin;

        if(amin == a2)
        {
            c2++;
        }

        if(amin == a3)
        {
            c3++;
        }

        if(amin == a5)
        {
            c5++;
        }

        if(amin == a7)
        {
            c7++;
        }
    }

    while(scanf("%d", &n) == 1)
    {
        if(n == 0)
        {
            break;
        }
        else
        {
            printf("The %d", n);
            switch(n % 100)
            {
            case 11:
            case 12:
            case 13:
            case 14:
            case 15:
            case 16:
            case 17:
            case 18:
            case 19:
                printf("th");
                break;
            default:
                switch(n % 10)
                {
                case 1:
                    printf("st");
                    break;
                case 2:
                    printf("nd");
                    break;
                case 3:
                    printf("rd");
                    break;
                default:
                    printf("th");
                    break;
                }
                break;
            }
            printf(" humble number is %d.\n", a[n - 1]);
        }
    }

    return 0;
}

