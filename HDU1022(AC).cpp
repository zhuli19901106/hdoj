#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int a[10];
int b[10];
int n;

int path[100];
int pc;

int sss[100];
int sp;

int main()
{
    char s[20];
    int i, j;

    while(scanf("%d", &n) == 1){
        scanf("%s", s);
        for(i = 1; i <= n; ++i){
            a[i] = s[i - 1] - '0';
        }
        scanf("%s", s);
        for(i = 1; i <= n; ++i){
            b[i] = s[i - 1] - '0';
        }

        sp = 0;
        pc = 0;
        i = 1;
        j = 1;
        while(true){
            if(i > n && j > n){
                break;
            }
            if(i <= n && j <= n){
                if(sp > 0 && sss[sp - 1] == b[j]){
                    --sp;
                    ++j;
                    path[pc++] = 1;
                }else if(a[i] == b[j]){
                    ++i;
                    ++j;
                    path[pc++] = 0;
                    path[pc++] = 1;
                }else{
                    sss[sp++] = a[i];
                    ++i;
                    path[pc++] = 0;
                }
            }else if(sp > 0 && sss[sp - 1] == b[j]){
                --sp;
                ++j;
                path[pc++] = 1;
            }else{
                //mismatch in a stack sequence
                break;
            }
        }
        if(sp == 0){
            printf("Yes.\n");
            for(i = 0; i < pc; ++i){
                if(path[i]){
                    printf("out\n");
                }else{
                    printf("in\n");
                }
            }
        }else{
            printf("No.\n");
        }
        printf("FINISH\n");
    }

    return 0;
}

