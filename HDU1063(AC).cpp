#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    char str[1050];

    int a[1000];
    int b[1000];
    int r[1000];

    int rexp;
    int exp;
    int ta;
    int tb;
    int tr;

    int n;
    int digit;

    int i;
    int j;
    int k;

    while(scanf("%s%d", str, &n) == 2)
    {
        for(i = 0; i < 1000; i++)
        {
            a[i] = 0;
            b[i] = 0;
            r[i] = 0;
        }

        for(i = strlen(str) - 1; i >= 0 && str[i] != '.'; i--)
        {

        }

        if(i > -1)
        {
            for(i = strlen(str) - 1; str[i] == '0'; i--)
            {
                str[i] = 0;
            }
        }

        for(i = strlen(str) - 1; i >= 0; i--)
        {
            if(str[i] == '.')
            {
                exp = (strlen(str) - 1 - i) * -1;
                break;
            }
        }

        if(i == -1)
        {
            exp = 0;
        }

        rexp = exp * n;

        j = 0;
        for(i = strlen(str) - 1; i >= 0; i--)
        {
            if(str[i] >= '0' && str[i] <= '9')
            {
                a[j] = str[i] - '0';
                b[j] = str[i] - '0';
                j++;
            }
            else if(str[i] == '.')
            {
                continue;
            }
        }

        for(i = 1; i < n; i++)
        {
            for(j = 0; j < 1000; j++)
            {
                r[j] = 0;
            }

            ta = 999;
            tb = 999;
            while(a[ta] == 0)
                ta--;
            ta++;
            while(b[tb] == 0)
                tb--;
            tb++;

            for(j = 0; j < ta; j++)
            {
                for(k = 0; k < tb; k++)
                {
                    r[k + j] = r[k + j] + b[k] * a[j];
                    if(r[k + j] > 9)
                    {
                        r[k + j + 1] = r[k + j + 1] + r[k + j] / 10;
                        r[k + j] = r[k + j] % 10;
                    }
                }
            }

            for(j = 0; j < 1000; j++)
            {
                b[j] = r[j];
            }
        }

        if(n > 1)
        {
            tr = 999;
            while(r[tr] == 0)
                tr--;
            tr++;

            if(exp == 0)
            {
                for(j = tr - 1; j >= 0; j--)
                {
                    printf("%d", r[j]);
                }
                printf("\n");
            }
            else if(-exp * n >= tr)
            {
                printf(".");
                for(j = 0; j < (-exp * n) - tr; j++)
                {
                    printf("0");
                }
                for(j = tr - 1; j >= 0; j--)
                {
                    printf("%d", r[j]);
                }
                printf("\n");
            }
            else
            {
                for(j = tr - 1; j >= 0; j--)
                {
                    printf("%d", r[j]);
                    if(j == -exp * n)
                    {
                        printf(".");
                    }
                }
                printf("\n");
            }
        }
        else if(n == 1)
        {
            for(j = 0; j < 1000; j++)
            {
                r[j] = a[j];
            }
            tr = 999;
            while(r[tr] == 0)
                tr--;
            tr++;

            if(exp == 0)
            {
                for(j = tr - 1; j >= 0; j--)
                {
                    printf("%d", r[j]);
                }
                printf("\n");
            }
            else if(-exp * n >= tr)
            {
                printf(".");
                for(j = 0; j < (-exp * n) - tr; j++)
                {
                    printf("0");
                }
                for(j = tr - 1; j >= 0; j--)
                {
                    printf("%d", r[j]);
                }
                printf("\n");
            }
            else
            {
                for(j = tr - 1; j >= 0; j--)
                {
                    printf("%d", r[j]);
                    if(j == -exp * n)
                    {
                        printf(".");
                    }
                }
                printf("\n");
            }
        }
    }

    return 0;
}

