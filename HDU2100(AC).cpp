#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main()
{
    char s[1000];
    int a[1000];
    int b[1000];
    int c[1000];
    int i;
    int len;

    while(scanf("%s", &s) == 1){
        memset(a, 0, 1000 * sizeof(int));
        len = strlen(s);
        for(i = 0; i < len; ++i){
            a[i] = s[len - 1 - i] - 'A';
        }
        scanf("%s", s);
        memset(b, 0, 1000 * sizeof(int));
        len = strlen(s);
        for(i = 0; i < len; ++i){
            b[i] = s[len - 1 - i] - 'A';
        }

        memset(c, 0, 1000 * sizeof(int));

        for(i = 0; i < 1000; ++i){
            c[i] = a[i] + b[i];
        }
        for(i = 0; i < 999; ++i){
            c[i + 1] += c[i] / 26;
            c[i] %= 26;
        }
        c[999] %= 26;

        i = 999;
        while(i >= 0 && c[i] == 0){
            --i;
        }
        if(i < 0){
            printf("A\n");
        }else{
            while(i >= 0){
                printf("%c", c[i] + 'A');
                --i;
            }
            printf("\n");
        }
    }

    return 0;
}

