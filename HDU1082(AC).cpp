#define _CRT_SECURE_NO_WARNINGS
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef struct Matrix{
    char name;
    long row;
    long col;
}Matrix;

int main()
{
    long len;
    long i;
    long j;
    long n;
    long top;
    Matrix stack[1000];
    Matrix matrices[1000];
    char line[1000];
    long multiplication;
    long error;

    gets(line);
    sscanf(line, "%ld", &n);
    for(i = 0; i < n; i++)
    {
        gets(line);
        sscanf(line, "%c %ld %ld", &matrices[i].name, &matrices[i].row, &matrices[i].col);
    }

    while(1)
    {
        if(gets(line) == NULL)
        {
            break;
        }

        len = strlen(line);
        top = -1;
        error = 0;
        multiplication = 0;
        for(i = 0; i < len && error == 0; i++)
        {
            if(isupper(line[i]))
            {
                for(j = 0; j < n; j++)
                {
                    if(matrices[j].name == line[i])
                    {
                        break;
                    }
                }

                if(j >= 0 && j <= n - 1)
                {
                    top++;
                    stack[top] = matrices[j];
                }
            }
            else if(line[i] == '(')
            {
            }
            else if(line[i] == ')')
            {
                if(top < 1)
                {
                    error = 1;
                }
                else if(stack[top - 1].col != stack[top].row)
                {
                    error = 1;
                }
                else
                {
                    multiplication = multiplication + stack[top - 1].row * stack[top - 1].col * stack[top].col;
                    top--;
                    stack[top].col = stack[top + 1].col;
                }
            }
        }

        if(top != 0)
        {
            error = 1;
        }

        if(error == 1)
        {
            printf("error\n");
        }
        else
        {
            printf("%ld\n", multiplication);
        }
    }

    return 0;
}

