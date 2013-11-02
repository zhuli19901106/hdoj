#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int a[6000];
int n;
int cc;

int main()
{
    int i, j;
    int f;
    int t, ti;

    while(scanf("%d", &t) == 1){
        for(ti = 0; ti < t; ++ti){
            scanf("%d", &n);
            memset(a, 0, 6000 * sizeof(int));
            cc = n;
            f = 0;
            while(cc > 3){
                if(f){
                    j = 0;
                    for(i = 1; i <= n; ++i){
                        if(!a[i]){
                            ++j;
                            if(j == 3){
                                a[i] = 1;
                                j = 0;
                                --cc;
                            }
                        }    
                    }
                }else{
                    j = 0;
                    for(i = 1; i <= n; ++i){
                        if(!a[i]){
                            ++j;
                            if(j == 2){
                                a[i] = 1;
                                j = 0;
                                --cc;
                            }
                        }
                    }
                }
                f = !f;
            }

            cc = 0;
            for(i = 1; i <= n; ++i){
                if(!a[i]){
                    printf((cc ? " %d" : "%d"), i);
                    ++cc;
                }
            }
            printf("\n");
        }
    }

    return 0;
}

