#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

int main()
{
    int n, m;
    int i, sum;
    int cc;

    while(scanf("%d%d", &n, &m) == 2){
        sum = 0;
        cc = 0;
        for(i = 1; i <= n; ++i){
            sum += i * 2;
            if(i % m == 0){
                if(cc > 0){
                    printf(" %d", sum / m);
                }else{
                    printf("%d", sum / m);
                }
                ++cc;
                sum = 0;
            }else if(i == n){
                if(cc > 0){
                    printf(" %d", sum / (n % m));
                }else{
                    printf("%d", sum / (n % m));
                }
                ++cc;
                sum = 0;
            }
        }
        printf("\n");
    }

    return 0;
}

