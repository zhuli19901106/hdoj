#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
using namespace std;

char dict[] = " !$%()*";
int dlen;

int main()
{
    int len;
    int i;
    int j;
    char buffer[1000];

    dlen = strlen(dict);
    while(1)
    {
        gets(buffer);

        if(strcmp(buffer, "#") == 0)
        {
            break;
        }
        len = strlen(buffer);

        for(i = 0; i < len; i++)
        {
            for(j = 0; j < dlen; j++)
            {
                if(buffer[i] == dict[j])
                {
                    break;
                }
            }

            if(j == dlen)
            {
                printf("%c", buffer[i]);
            }
            else
            {
                printf("%%%2x", (int)buffer[i]);
            }
        }
        printf("\n");
    }

    return 0;
}

