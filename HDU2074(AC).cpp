#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

char s[2];
char str[10];
int n;
char f[100][100];
int b;
int ti;
int x, y;
int len;

int main()
{
    int i;
    int ti;

    ti = 0;
    while(scanf("%d", &n) == 1){
        ++ti;
        if(ti > 1){
            printf("\n");
        }

        scanf("%s", str);
        s[0] = str[0];
        scanf("%s", str);
        s[1] = str[0];

        if(n == 1){
            printf("%c\n", s[0]);
            continue;
        }

        b = 0;
        x = (n - 1) / 2;
        y = (n - 1) / 2;
        len = 1;
        memset(f, 0, 100 * 100 * sizeof(char));
        while(len <= n){
            for(i = 0; i < len; ++i){
                f[x][y + i] = s[b];
                f[x + len - 1][y + i] = s[b];
                f[x + i][y] = s[b];
                f[x + i][y + len - 1] = s[b];
            }
            --x;
            --y;
            len += 2;
            b = !b;
        }

        f[0][0] = f[n - 1][0] = ' ';
        f[0][n - 1] = f[n - 1][n - 1] = ' ';
        for(i = 0; i < n; ++i){
            puts(f[i]);
        }
    }

    return 0;
}

