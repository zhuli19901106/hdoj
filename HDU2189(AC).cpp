#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAXN = 151;
int b[MAXN];
int p[MAXN];
int pc;
int res[MAXN];

void dfs(int index, int sum)
{
    int i;

    if(sum >= MAXN){
        return;
    }else if(sum > 0){
        ++res[sum];
    }

    for(i = index; i < pc; ++i){
        if(sum + p[i] >= MAXN){
            break;
        }else{
            dfs(i, sum + p[i]);
        }
    }
}

int main()
{
    int i, j;
    int t, ti;
    int n;

    memset(b, 0, MAXN * sizeof(int));
    b[0] = b[1] = 1;
    for(i = 2; i * i < MAXN; ++i){
        if(b[i]){
            continue;
        }
        for(j = i; j * i < MAXN; ++j){
            b[j * i] = 1;
        }
    }

    pc = 0;
    for(i = 0; i < MAXN; ++i){
        b[i] = !b[i];
        if(b[i]){
            p[pc++] = i;
        }
    }

    dfs(0, 0);

    while(scanf("%d", &t) == 1){
        for(ti = 0; ti < t; ++ti){
            scanf("%d", &n);
            printf("%d\n", res[n]);
        }
    }

    return 0;
}

