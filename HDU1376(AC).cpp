#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAXN = 2000;
int a[MAXN];
int b[MAXN];
char s[MAXN];
int f[10][4] = {
    {0, 0, 0, 0}, {0, 1, 2, 5}, {0, 2, 5, 0}, {0, 3, 7, 5}, {0, 5, 0, 0}, 
    {0, 6, 2, 5}, {0, 7, 5, 0}, {0, 8, 7, 5}, {1, 0, 0, 0}, {1, 1, 2, 5}
};

int main()
{
    int len, i, j;

    while(scanf("%s", s) == 1){
        memset(a, 0, MAXN * sizeof(int));
        memset(b, 0, MAXN * sizeof(int));
        if(s[0] == '1'){
            printf("%s [8] = 1 [10]\n", s);
            continue;
        }

        len = strlen(s);
        i = len - 1;
        j = 0;
        while(s[i] != '.'){
            memset(b, 0, MAXN * sizeof(int));
            for(j = 0; j < MAXN - 3; ++j){
                if(a[j] > 0){
                    b[j] += f[a[j]][0];
                    b[j + 1] += f[a[j]][1];
                    b[j + 2] += f[a[j]][2];
                    b[j + 3] += f[a[j]][3];
                }else{
                    continue;
                }
            }
            b[0] += f[s[i] - '0'][1];
            b[1] += f[s[i] - '0'][2];
            b[2] += f[s[i] - '0'][3];
            for(j = MAXN - 1; j > 0; --j){
                b[j - 1] += b[j] / 10;
                b[j] %= 10;
            }
            b[0] %= 10;
            memcpy(a, b, MAXN * sizeof(int));
            --i;
        }

        printf("%s [8] = ", s);
        j = MAXN - 1;
        while(j >= 0 && a[j] == 0){
            --j;
        }
        if(j >= 0){
            printf("0.");
            for(i = 0; i <= j; ++i){
                printf("%d", a[i]);
            }
        }else{
            printf("0");
        }
        printf(" [10]\n");
    }

    return 0;
}

