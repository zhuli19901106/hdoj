#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
using namespace std;

int allzero(int ta[][2], int ca)
{
    int i;

    for(i = 0; i < ca; i++)
    {
        if(ta[i][1] > 0)
        {
            return 0;
        }
    }

    return 1;
}

void printdigits(int ta[][2], int ca)
{
    int i;

    for(i = 0; i < ca; i++)
    {
        if(i == 0)
        {
            printf("%d", ta[i][1]);
        }
        else
        {
            printf(" %d", ta[i][1]);
        }
    }
}

int getsum(int ta[][2], int ca)
{
    int i;
    int checksum;

    checksum = 0;
    for(i = 0; i < ca; i++)
    {
        if(ta[i][1] > 0)
        {
            checksum = checksum + ta[i][0] * ta[i][1];
        }
    }

    return checksum;
}

void printsum(int ta[][2], int ca)
{
    int ii;
    int jj;
    int left;
    int right;

    for(left = 0; ta[left][1] == 0; left++);
    for(right = ca - 1; ta[right][1] == 0; right--);

    for (ii = left; ii <= right; ii++)
    {
        if (ta[ii][1] > 0)
        {
            if(ii == left)
            {
                for(jj = 0; jj < ta[ii][1]; jj++)
                {
                    if(jj == 0)
                    {
                        printf("%d", ta[ii][0]);
                    }
                    else
                    {
                        printf("+%d", ta[ii][0]);
                    }
                }
            }
            else
            {
                for(jj = 0; jj < ta[ii][1]; jj++)
                {
                    printf("+%d", ta[ii][0]);
                }
            }
        }
    }
}

/*
void dfs(int h, int t)
{
    int ii;
    int jj;

    if (t == 0)
    {
        failed = 0;
        // succeeded
    }
    else
    {
        if((a[h][0] <= t) && (a[h][1] > 0))
        {
            a[h][1]--;
            ta[h][1]++;
            for (ii = 0; ii < ca - h; ii++)
            {
                if(h + ii >= 0 && h + ii < ca && t - a[h + ii][0] >= 0)
                {
                    dfs(h + ii, t - a[h + ii][0]);
                }
            }
            a[h][1]++;
            ta[h][1]--;
        }
    }
}
*/

int main()
{
    int n;
    int t;
    int i;
    int j;
    int k;
    int b[200];
    int tmp;
    int checksum;
    int a[12][2];
    int ta[12][2];
    int ca;
    int successcount;

    while(1)
    {
        successcount = 0;

        scanf("%d%d", &t, &n);
        if(n == 0)
        {
            break;
        }

        ca = 0;
        memset(b, 0, 200 * sizeof(int));
        for(i = 0; i < n; i++)
        {
            scanf("%d", &tmp);
            b[tmp]++;
        }

        for(i = 199; i >= 0; i--)
        {
            if(b[i] > 0)
            {
                a[ca][0] = i;
                a[ca][1] = b[i];
                ca++;
            }
        }

        /*
        for(int ii = 0; ii < ca; ii++)
        {
            for(i = 0; i < 12; i++)
            {
                ta[i][0] = a[i][0];
                ta[i][1] = 0;
            }
            printf("---%d---\n", ii);
            dfs(ii, t);
            printf("--------\n");
        }
        */

        for(i = 0; i < ca; i++)
        {
            ta[i][0] = a[i][0];
            ta[i][1] = a[i][1];
        }

        printf("Sums of %d:\n", t);
        while(!allzero(ta, ca))
        {
            //printdigits(ta, ca);
            //printf("\n");

            checksum = getsum(ta, ca);
            if(checksum == t)
            {
                printsum(ta, ca);
                printf("\n");
                successcount++;
            }

            for(j = ca - 1; j >= 0; j--)
            {
                if(ta[j][1] > 0)
                {
                    break;
                }
            }

            if(j == -1)
            {
                break;
            }

            for(k = ca - 1; k > j; k--)
            {
                ta[k][1] = a[k][1];
            }
            ta[j][1]--;
        }

        if(successcount == 0)
        {
            printf("NONE\n");
        }
    }

    return 0;
}

