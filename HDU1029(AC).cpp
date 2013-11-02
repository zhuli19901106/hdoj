#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int n;
int res, tmp;
int cc;

int main()
{
    int i;

    while(scanf("%d", &n) == 1){
        scanf("%d", &res);
        cc = 1;

        for(i = 1; i < n; ++i){
            scanf("%d", &tmp);
            if(tmp != res){
                --cc;
                if(cc == 0){
                    res = tmp;
                    cc = 1;
                }
            }else{
                ++cc;
            }
        }

        printf("%d\n", res);
    }

    return 0;
}

