#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int h[5001];
int hs[10001];
int a[3000];
int b[3000];
int cc;
int n, m;

int main()
{
    int tmp;
    int i, j;

    while(scanf("%d%d", &n, &m) == 2){
        memset(h, 0, 5001 * sizeof(int));
        for(i = 0; i < n; ++i){
            scanf("%d",&tmp);
            ++h[tmp];
        }
        cc = 0;
        for(i = 5000; i >= 0; --i){
            if(h[i] > 0){
                a[cc] = i;
                b[cc] = h[i];
                ++cc;
            }
        }
        memset(hs, 0, 10001 * sizeof(int));
        for(i = 0; i < cc; ++i){
            hs[2 * a[i]] += b[i] * (b[i] - 1) / 2;
        }
        for(i = 0; i < cc; ++i){
            for(j = i + 1; j < cc; ++j){
                hs[a[i] + a[j]] += b[i] * b[j];
            }
        }

        cc = 0;
        for(i = 10000; i >= 0; --i){
            if(hs[i] > 0){
                if(m >= hs[i]){
                    for(j = 0; j < hs[i]; ++j){
                        if(cc == 0){
                            printf("%d", i);
                        }else{
                            printf(" %d", i);
                        }
                        ++cc;
                    }
                    m -= hs[i];
                }else{
                    for(j = 0; j < m; ++j){
                        if(cc == 0){
                            printf("%d", i);
                        }else{
                            printf(" %d", i);
                        }
                        ++cc;
                    }
                    m = 0;
                    break;
                }
            }
        }
        printf("\n");
    }

    return 0;
}

