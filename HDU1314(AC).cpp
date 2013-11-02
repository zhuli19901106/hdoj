#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAXN = 40;
char s[MAXN], s1[MAXN];
int a[MAXN];
int a0[MAXN];
int len;

void reverse(char s[])
{
    int i, len;
    char ch;

    i = 0;
    len = strlen(s);
    while(i < len - 1 - i){
        ch = s[i];
        s[i] = s[len - 1 - i];
        s[len - 1 - i] = ch;
        ++i;
    }
}

void minus_one(int a[])
{
    int i;

    --a[0];
    for(i = 0; i < MAXN - 1; ++i){
        if(a[i] < 0){
            a[i] += 10;
            --a[i + 1];
        }else{
            break;
        }
    }
    if(a[MAXN - 1] < 0){
        a[MAXN - 1] += 10;
    }
}

int main()
{
    int i, j, r;

    while(scanf("%s", s) == 1 && strcmp(s, "*")){
        if(s[0] >= '0' && s[0] <= '9'){
            if(strcmp(s, "1") == 0){
                printf("%-22s1\n", "a");
                continue;
            }
            //number to word
            memset(a, 0, MAXN * sizeof(int));
            len = strlen(s);
            for(i = 0; i < len; ++i){
                a[i] = s[len - 1 - i] - '0';
            }

            memcpy(a0, a, MAXN * sizeof(int));
            len = 0;
            while(true){
                i = MAXN - 1;
                while(i >= 0 && a[i] == 0){
                    --i;
                }
                if(i < 0){
                    break;
                }

                for(i = MAXN - 1; i > 0; --i){
                    a[i - 1] += a[i] % 26 * 10;
                    a[i] = a[i] / 26;
                }
                r = a[0] % 26;
                a[0] = a[0] / 26;
                if(r > 0){
                    s[len++] = 'a' + r - 1;
                }else{
                    s[len++] = 'z';
                    minus_one(a);
                }
            }
            memcpy(a, a0, MAXN * sizeof(int));
            s[len] = 0;

            reverse(s);
            printf("%-22s", s);
            i = MAXN - 1;
            while(i >= 0 && a[i] == 0){
                --i;
            }
            while(i >= 0){
                printf("%d", a[i]);
                if(i > 0 && i % 3 == 0){
                    printf(",");
                }
                --i;
            }
            printf("\n");
        }else{
            //word to number
            memset(a, 0, MAXN * sizeof(int));
            for(i = 0; s[i]; ++i){
                for(j = 0; j < MAXN; ++j){
                    a[j] *= 26;
                }
                a[0] += s[i] - 'a' + 1;

                for(j = 0; j < MAXN - 1; ++j){
                    a[j + 1] += a[j] / 10;
                    a[j] %= 10;
                }
                a[j] %= 10;
            }

            printf("%-22s", s);
            i = MAXN - 1;
            while(i >= 0 && a[i] == 0){
                --i;
            }
            while(i >= 0){
                printf("%d", a[i]);
                if(i > 0 && i % 3 == 0){
                    printf(",");
                }
                --i;
            }
            printf("\n");
        }
    }

    return 0;
}

