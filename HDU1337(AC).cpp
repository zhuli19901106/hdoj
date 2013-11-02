#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    int i;
    int j;
    int k;
    int t;
    int n;
    int a[101];
    int count;

    scanf("%d", &t);
    for(i = 0; i < t; i++){
        scanf("%d", &n);
        memset(a, 0, 101 * sizeof(int));

        for(j = 2; j <= n; j++){
            for(k = j; k <= n; k = k + j){
                if(a[k] == 1){
                    a[k] = 0;
                }else{
                    a[k] = 1;
                }
            }
        }

        count = 0;
        for(j = 1; j <= n; j++){
            if(a[j] == 0){
                count++;
            }
        }

        printf("%d\n", count);
    }

    return 0;
}

