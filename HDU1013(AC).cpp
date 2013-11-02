#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
using namespace std;

void compress(char a[])
{
    int i;
    int len;
    int sum;

    len = strlen(a);
    sum = 0;
    for(i = 0; i < len; i++)
    {
        if(a[i] >= '1' && a[i] <= '9')
        {
            sum = sum + a[i] - '0';
        }
    }

    sprintf(a, "%d", sum);
}

int main()
{
    char buffer[1000];

    while(1)
    {
        gets(buffer);
        if(strcmp(buffer, "0") == 0)
        {
            break;
        }

        while(strlen(buffer) !=  1)
        {
            compress(buffer);
        }

        puts(buffer);
    }

    return 0;
}

