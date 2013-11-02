#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int bt[16];
int hash[70000];
int b2[16] = {
    1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768
};
int a, b, c, s;

void check(int s)
{
    int i;

    for(i = 0; i < 16; ++i){
        if(s & b2[i]){
            bt[i] |= 2;
        }else{
            bt[i] |= 1;
        }
    }
}

int main()
{
    int i;

    while(scanf("%d", &a) == 1 && a){
        scanf("%d%d%d", &b, &c, &s);
        memset(hash, 0, 70000 * sizeof(int));
        memset(bt, 0, 16 * sizeof(int));
        check(s);
        hash[s] = 1;
        while(true){
            s = (a * s + b) % c;
            if(hash[s]){
                break;
            }else{
                check(s);
                hash[s] = 1;
            }
        }

        for(i = 15; i >= 0; --i){
            if(bt[i] == 1){
                putchar('0');
            }else if(bt[i] == 2){
                putchar('1');
            }else if(bt[i] == 3){
                putchar('?');
            }else{
                //impossible
            }
        }
        putchar('\n');
    }

    return 0;
}

