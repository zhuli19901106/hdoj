#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
using namespace std;

void reverse(const char input[], char output[], int start, int end)
{
    int j;

    if(start > end)
    {
        output[0] = 0;
        return;
    }
    else if(start == end)
    {
        strcpy(output, input);
        return;
    }

    for(j = 0; j < start; j++)
    {
        output[j] = input[j];
    }
    for(j = start; j <= end; j++)
    {
        output[j] = input[start + end - j];
    }
    for(j = end + 1; j < strlen(input); j++)
    {
        output[j] = input[j];
    }
    output[j] = 0;
}

int main()
{
    char thisp[100];
    char nextp[100];
    char buffer[500];
    char ch;
    int p;
    int n;
    int i;
    int j;
    int cut;
    int swap;

    gets(buffer);
    sscanf(buffer, "%d", &p);
    for(i = 0; i < p; i++)
    {
        gets(buffer);
        sscanf(buffer, "%d %s", &n, thisp);
        for(j = 0; j < strlen(thisp) - 1; j++)
        {
            if(thisp[j] < thisp[j + 1])
            {
                break;
            }
        }
        if(j == strlen(thisp) - 1)
        {
            printf("%d BIGGEST\n", n);
        }
        else
        {
            for(cut = strlen(thisp) - 2; cut >= 0; cut--)
            {
                if(thisp[cut] < thisp[cut + 1])
                {
                    break;
                }
            }

            for(swap = strlen(thisp) - 1; swap > cut; swap--)
            {
                if(thisp[swap] > thisp[cut])
                {
                    break;
                }
            }
            ch = thisp[cut];
            thisp[cut] = thisp[swap];
            thisp[swap] = ch;
            reverse(thisp, nextp, cut + 1, strlen(thisp) - 1);
            printf("%d %s\n", n, nextp);
        }
    }

    return 0;
}

