#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int a[1000], s, t;
int mi;

int main()
{
    int i;
    int n, ni;
    int res;

    while(scanf("%d", &n) == 1){
        for(ni = 0; ni < n; ++ni){
            memset(a, 0, 1000 * sizeof(int));
            scanf("%d%d", &t, &mi);
            s = 0;
            for(i = 0; i < t; ++i){
                scanf("%d", &a[s + i]);
            }
            res = 0;
            while(true){
                if(s > 100){
                    for(i = 0; i < t; ++i){
                        a[i] = a[s + i];
                    }
                    s = 0;
                }

                for(i = 1; i < t; ++i){
                    if(a[s] < a[s + i]){
                        a[s + t] = a[s];
                        if(mi == 0){
                            mi = t - 1;
                        }else{
                            --mi;
                        }
                        a[s] = 0;
                        ++s;
                        break;
                    }
                }

                if(i == t){
                    if(mi == 0){
                        ++res;
                        break;
                    }else{
                        ++res;
                        a[s] = 0;
                        ++s;
                        --t;
                        --mi;
                    }
                }
            }

            printf("%d\n", res);
        }
    }
    return 0;
}

