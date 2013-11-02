#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;

int a[1001];
int n, m;

int main()
{
    int i;
    
    while(scanf("%d%d", &n, &m) == 2){
        for(i = 1; i <= n; ++i){
            a[i] = i;
        }
        for(i = 1; i < m; ++i){
            next_permutation(a + 1, a + n + 1);
        }

        for(i = 1; i <= n; ++i){
            if(i > 1){
                printf(" %d", a[i]);
            }else{
                printf("%d", a[i]);
            }
        }
        printf("\n");
    }

    return 0;
}

