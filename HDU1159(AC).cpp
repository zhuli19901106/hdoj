#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

char *a;
char *b;
char *tmp;

int min(int a, int b)
{
    if(a > b)
    {
        return b;
    }
    else
    {
        return a;
    }
}

int max(int a, int b)
{
    if(a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int same(int i, int j)
{
    return a[i] == b[j];
}

int main()
{
    int i;
    int j;
    int lena;
    int lenb;
    int cur;
    int f[2][10000];

    a = (char *)malloc(10000 * sizeof(char));
    b = (char *)malloc(10000 * sizeof(char));
    tmp = (char *)malloc(10000 * sizeof(char));

    while(1)
    {
        if(scanf("%s%s", a, b) != 2)
        {
            break;
        }

        if(strlen(a) < strlen(b))
        {
            strcpy(tmp, a);
            strcpy(a, b);
            strcpy(b, tmp);
        }

        lena = strlen(a);
        lenb = strlen(b);

        for(i = 0; i < 10000; i++)
        {
            f[0][i] = f[1][i] = 0;
        }

        if(lenb == 1)
        {
            for(i = 0; i < lena; i++)
            {
                if(a[i] == b[0])
                {
                    break;
                }
            }

            if(i == lena)
            {
                printf("0\n");
            }
            else
            {
                printf("1\n");
            }
        }
        else
        {
            cur = 0;
            for(i = 0; i < lena; i++)
            {
                for(j = 0; j < lenb; j++)
                {
                    if(a[i] == b[j])
                    {
                        f[cur][j + 1] = f[!cur][j] + 1;
                    }
                    else
                    {
                        f[cur][j + 1] = max(f[cur][j], f[!cur][j + 1]);
                    }
                }
                cur = !cur;
            }
            printf("%d\n", f[!cur][lenb]);
        }
    }

    free(a);
    free(b);
    free(tmp);

    return 0;
}

