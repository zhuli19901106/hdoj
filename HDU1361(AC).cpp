#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int findmatch(char s[], int a, int n)
{
    int stack;
    int i;

    if(s[a] != ')')
    {
        return -1;
    }

    stack = 0;
    for(i = a; i >= 0; i--)
    {
        if(s[i] == ')')
        {
            stack++;
        }
        else if(s[i] == '(')
        {
            stack--;
            if(stack == 0)
            {
                return i;
            }
        }
    }
}

int main()
{
    int i;
    int j;
    int k;
    int match;
    int cw;
    int l;
    int n;
    int t;
    int p[100];
    int w[100];
    char s[201];

    scanf("%d", &t);
    for(i = 0; i < t; i++)
    {
        scanf("%d", &n);
        for(j = 0; j < n; j++)
        {
            scanf("%d", &p[j]);
            w[j] = 0;
        }

        l = 0;
        for(j = 0; j < n; j++)
        {
            if(j == 0)
            {
                for(k = 0; k < p[j]; k++)
                {
                    s[l + k] = '(';
                }
                s[l + k] = ')';
                l = l + p[j] + 1;
            }
            else
            {
                for(k = 0; k < p[j] - p[j - 1]; k++)
                {
                    s[l + k] = '(';
                }
                s[l + k] = ')';
                l = l + p[j] - p[j - 1] + 1;
            }
        }
        s[2 * n] = 0;

        cw = 0;
        for(j = 0; j < 2 * n; j++)
        {
            if(s[j] == ')')
            {
                match = findmatch(s, j, 2 * n);
                for(k = match; k <= j; k++)
                {
                    if(s[k] == ')')
                    {
                        w[cw]++;
                    }
                }
                cw++;
            }
        }

        for(j = 0; j < n; j++)
        {
            if(j == n - 1)
            {
                printf("%d\n", w[j]);
            }
            else if(j < n - 1)
            {
                printf("%d ", w[j]);
            }
        }
    }
    
    return 0;
}

