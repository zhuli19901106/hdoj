#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int res[251];
const int MAXT = 5;
int v[MAXT] = {50, 25, 10, 5, 1};

void dfs(int sum, int idx, int cnt)
{
    if(cnt >= 100){
        return;
    }
    if(sum >= 250){
        return;
    }
    if(idx >= MAXT){
        return;
    }

    int i;

    for(i = 0; cnt + i <= 100 && sum + i * v[idx] <= 250; ++i){
        if(i > 0){
            ++res[sum + i * v[idx]];
        }
        /*
        if(sum + i * v[idx] == 5){
            printf("sum = %d,  idx = %d, cnt = %d, i = %d\n", sum + i * v[idx], idx, cnt, i);
        }
        */
        dfs(sum + i * v[idx], idx + 1, cnt + i);
    }
}

int main()
{
    int n;

    dfs(0, 0, 0);
    res[0] = 1;

    while(scanf("%d", &n) == 1){
        printf("%d\n", res[n]);
    }

    return 0;
}

