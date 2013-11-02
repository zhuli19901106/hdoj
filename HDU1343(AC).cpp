#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAXN = 2001;
int a[MAXN], b[MAXN], c[MAXN], p[MAXN];
int ac, bc, cc, pc;

void print_array(const int p[])
{
    int i;

    if(!p){
        return;
    }

    i = MAXN - 1;
    while(i >= 0 && !p[i]){
        --i;
    }
    printf("%d", i + 1);
    while(i >= 0){
        printf(" %d", p[i]);
        --i;
    }
    printf("\n");
}

int main()
{
    int i, j;
    int t;
    int ll, rr;

    while(scanf("%d", &t) == 1){
        while(t--){
            //memory initialization
            memset(a, 0, MAXN * sizeof(int));
            memset(b, 0, MAXN * sizeof(int));
            memset(c, 0, MAXN * sizeof(int));
            memset(p, 0, MAXN * sizeof(int));

            //data input
            scanf("%d", &ac);
            for(i = ac - 1; i >= 0; --i){
                scanf("%d", &a[i]);
            }
            scanf("%d", &bc);
            for(i = bc - 1; i >= 0; --i){
                scanf("%d", &b[i]);
            }
            scanf("%d", &cc);
            for(i = cc - 1; i >= 0; --i){
                scanf("%d", &c[i]);
            }

            //binary multiplication
            for(i = 0; i < ac; ++i){
                if(!a[i]){
                    continue;
                }
                for(j = 0; j < bc; ++j){
                    p[i + j] ^= a[i] & b[j];
                }
            }

            //modular operation
            pc = MAXN - 1;
            while(pc >= 0 && !p[pc]){
                --pc;
            }

            --cc;
            while(true){
                ll = pc;
                rr = pc - cc;
                if(rr < 0){
                    break;
                }

                for(i = rr; i <= ll; ++i){
                    p[i] ^= c[i - rr];
                }

                while(pc >= 0 && !p[pc]){
                    --pc;
                }
            }

            //output the result
            print_array(p);
        }
    }

    return 0;
}

