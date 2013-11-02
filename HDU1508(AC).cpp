#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
#define DATASIZE 100000
int main()
{
    int i;
    int len;
    int *a;
    int d;
    char *buffer;

    a = (int *)malloc(DATASIZE * sizeof(int));
    buffer = (char *)malloc(DATASIZE * sizeof(char));

    while(1)
    {
        if(scanf("%s", buffer) != 1)
        {
            break;
        }
        else if(strcmp(buffer, "0") == 0)
        {
            break;
        }

        memset(a, 0, DATASIZE * sizeof(int));
        len = strlen(buffer);

        if(len == 1)
        {
            printf("1\n");
        }
        else if(len == 2)
        {
            d = (buffer[0] - '0') * 10 + (buffer[1] - '0');
            if(d > 26 || d == 10 || d == 20)
            {
                printf("1\n");
            }
            else if(d >= 10 && d <= 26)
            {
                printf("2\n");
            }
        }
        else if(len > 2)
        {
            a[0] = 1;
            d = (buffer[0] - '0') * 10 + (buffer[1] - '0');
            if(d > 26 || d == 10 || d == 20)
            {
                a[1] = 1;
            }
            else if(d >= 1 && d <= 26)
            {
                a[1] = 2;
            }

            for(i = 2; i < len; i++)
            {
                d = (buffer[i - 1] - '0') * 10 + (buffer[i] - '0');
                if(d >= 1 && d <= 9)
                {
                    a[i] = a[i - 1];
                }
                else if(d == 10 || d == 20)
                {
                    a[i] = a[i - 2];
                }
                else if(d > 26)
                {
                    a[i] = a[i - 1];
                }
                else if(d >= 11 && d <= 26)
                {
                    a[i] = a[i - 1] + a[i - 2];
                }
            }

            printf("%d\n", a[len - 1]);
        }
    }

    return 0;
}

