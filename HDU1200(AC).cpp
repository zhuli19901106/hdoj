#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
using namespace std;

void reverse(char a[], int left, int right)
{
    char ch;
    int i;
    int j;

    i = left;
    j = right;
    while(i < j)
    {
        ch = a[i];
        a[i] = a[j];
        a[j] = ch;
        i++;
        j--;
    }
}

int main()
{
    int i;
    int len;
    int row;
    int col;
    char str[1000];
    char result[1000];

    while(1)
    {
        gets(str);
        sscanf(str, "%d", &col);
        if(col == 0)
        {
            break;
        }

        gets(str);
        len = strlen(str);
        row = len / col;
        for(i = 1; i <= row - 1; i = i + 2)
        {
            reverse(str, i * col, (i + 1) * col - 1);
        }
        for(i = 0; i < len; i++)
        {
            result[(i % col) * row + (i / col)] = str[i];
        }
        result[i] = 0;
        puts(result);
    }

    return 0;
}

