#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int n, k, nk;
int p1, p2;
char m1[1000], m2[1000];
char c1, c2;
int w[105], l[105];

int main()
{
    int i;
    int ti;

    ti = 0;
    while(scanf("%d", &n) == 1 && n){
        scanf("%d", &k);
        nk = k * n * (n - 1) / 2;
        memset(w, 0, 105 * sizeof(int));
        memset(l, 0, 105 * sizeof(int));
        for(i = 0; i < nk; ++i){
            scanf("%d%s%d%s", &p1, m1, &p2, m2);

            if(strcmp(m1, "rock") == 0){
                c1 = 0;
            }else if(strcmp(m1, "scissors") == 0){
                c1 = 1;
            }else if(strcmp(m1, "paper") == 0){
                c1 = 2;
            }

            if(strcmp(m2, "rock") == 0){
                c2 = 0;
            }else if(strcmp(m2, "scissors") == 0){
                c2 = 1;
            }else if(strcmp(m2, "paper") == 0){
                c2 = 2;
            }

            if(c1 == 0 && c2 == 1){
                ++w[p1];
                ++l[p2];
            }else if(c1 == 1 && c2 == 2){
                ++w[p1];
                ++l[p2];
            }else if(c1 == 2 && c2 == 0){
                ++w[p1];
                ++l[p2];
            }else if(c1 == 1 && c2 == 0){
                ++w[p2];
                ++l[p1];
            }else if(c1 == 2 && c2 == 1){
                ++w[p2];
                ++l[p1];
            }else if(c1 == 0 && c2 == 2){
                ++w[p2];
                ++l[p1];
            }
        }

        if(ti > 0){
            printf("\n");
        }
        ++ti;

        for(i = 1; i <= n; ++i){
            if(w[i] + l[i]){
                printf("%.3f\n", 1.0 * w[i] / (w[i] + l[i]));
            }else{
                printf("-\n");
            }
        }
    }

    return 0;
}

