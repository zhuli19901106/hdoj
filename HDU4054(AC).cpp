#define _CRT_SECURE_NO_WARNINGS
#include <cctype>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    char buffer[5000];
    int len;
    int addr;
    int start;
    int end;
    int i;
    int j;

    while(1)
    {
        if(gets(buffer) == NULL)
        {
            break;
        }
        else
        {
            len = strlen(buffer);
        }

        addr = 0;
        i = 0;
        while(i < len)
        {
            printf("%04x: ", addr);
            if(i + 16 < len)
            {
                start = i;
                end = i + 16;
                for(j = i; j < i + 16; j = j + 2)
                {
                    printf("%02x%02x ", (int)buffer[j], (int)buffer[j + 1]);
                }
                i = i + 16;
            }
            else
            {
                start = i;
                end = len;
                if(len % 2 == 1)
                {
                    for(j = i; j < len - 2; j = j + 2)
                    {
                        printf("%02x%02x ", (int)buffer[j], (int)buffer[j + 1]);
                    }

                    printf("%02x", (int)buffer[len - 1]);
                    printf("   ");
                    j = j + 2;

                    while(j < i + 16)
                    {
                        printf("     ");
                        j = j + 2;
                    }
                }
                else
                {
                    for(j = i; j < len - 1; j = j + 2)
                    {
                        printf("%02x%02x ", (int)buffer[j], (int)buffer[j + 1]);
                    }

                    while(j < i + 16)
                    {
                        printf("     ");
                        j = j + 2;
                    }
                }

                i = len;
            }

            for(j = start; j < end; j++)
            {
                if(buffer[j] >= 'A' && buffer[j] <= 'Z')
                {
                    printf("%c", buffer[j] - 'A' + 'a');
                }
                else if(buffer[j] >= 'a' && buffer[j] <= 'z')
                {
                    printf("%c", buffer[j] - 'a' + 'A');
                }
                else
                {
                    printf("%c", buffer[j]);
                }
            }
            printf("\n");

            addr = addr + 16;
        }
    }

    return 0;
}

