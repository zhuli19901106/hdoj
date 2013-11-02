#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

int main()
{
    int n;
    int m;
    int t;
    int i;
    char buffer[1000];
    int a;
    int b;
    int count;
    int casecount;

    gets(buffer);
    sscanf(buffer, "%d", &t);
    for(i = 0; i < t; i++)
    {
        gets(buffer);
        casecount = 0;
        while(1)
        {
            gets(buffer);
            sscanf(buffer, "%d%d", &n, &m);
            if(n == 0 && m == 0)
            {
                if(i != t - 1)
                {
                    puts("");
                }
                break;
            }
            else
            {
                casecount++;
            }

            count = 0;
            for(a = 1; a <= n - 2; a++)
            {
                for(b = a + 1; b <= n - 1; b++)
                {
                    if((a * a + b * b + m) % (a * b) == 0)
                    {
                        count++;
                    }
                }
            }
            printf("Case %d: %d\n", casecount, count);
        }
    }

    return 0;
}

