#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
using namespace std;

int count[5][26];
int total[5];
int totalsum[6];

void reverse(char str[])
{
    int len;
    int i;
    int j;
    char ch;

    len = strlen(str);
    i = 0;
    j = len - 1;
    while(i < j)
    {
        ch = str[i];
        str[i] = str[j];
        str[j] = ch;
        i++;
        j--;
    }
}

int isvalid(char a[])
{
    int i;
    int len;

    if(a == NULL)
    {
        return 0;
    }

    len = strlen(a);
    for(i = 0; i < len - 1; i++)
    {
        if(a[i] >= a[i + 1])
        {
            return 0;
        }
    }

    return 1;
}

int main()
{
    char word[10];
    int len;
    int i;
    int j;
    int k;
    int index;
    char ch;

    for(i = 0; i < 26; i++)
    {
        count[0][i] = 1;
    }

    for(k = 0; k < 4; k++)
    {
        for(i = 0; i < 26; i++)
        {
            count[k + 1][i] = 0;
            for(j = i + 1; j < 26; j++)
            {
                count[k + 1][i] += count[k][j];
            }
        }
    }

    for(i = 0; i < 5; i++)
    {
        total[i] = 0;
        for(j = 0; j < 26; j++)
        {
            total[i] += count[i][j];
        }
    }

    totalsum[0] = 0;
    for(i = 0; i < 5; i++)
    {
        totalsum[i + 1] = totalsum[i] + total[i];
    }

    while(1)
    {
        if(gets(word) == NULL)
        {
            break;
        }
        else if((len = strlen(word)) == 0)
        {
            continue;
        }

        if(isvalid(word) == 0)
        {
            printf("0\n");
        }
        else
        {
            len = strlen(word);
            index = totalsum[len - 1] + 1;
            reverse(word);
            for(i = len - 1; i >= 0; i--)
            {
                ch = word[i];
                if(i == len - 1)
                {
                    for(j = 0; j < word[i] - 'a'; j++)
                    {
                        index += count[i][j];
                    }
                }
                else
                {
                    for(j = word[i + 1] - 'a' + 1; j < word[i] - 'a'; j++)
                    {
                        index += count[i][j];
                    }
                }
            }

            printf("%d\n", index);
        }
    }

    return 0;
}

