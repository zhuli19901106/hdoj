#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
    int a, b, c;
    int n;
    int score[22] = {
        0, 7, 13, 18, 22, 25, 27, 35, 43, 51, 59, 67, 75, 83, 91, 99, 107, 115, 123, 131, 139, 147
    };

    while(scanf("%d", &n) == 1){
        while(n--){
            scanf("%d%d%d", &a, &b, &c);
            if(score[a] >= c - b){
                printf("Yes\n");
            }else{
                printf("No\n");
            }
        }
    }

    return 0;
}

