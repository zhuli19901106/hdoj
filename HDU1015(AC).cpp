#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

bool suc;
int res[100];
int rc;
int target;
int v[100];
int visited[100];
int n;

int comp(const void *a, const void *b)
{
    return *(const int *)a - *(const int *)b;
}

int mypow(int n, int p)
{
    int sum;

    if(p == 0){
        return 1;
    }else if(p > 0){
        sum = 1;
        for(int i = 0; i < p; ++i){
            sum *= n;
        }

        return sum;
    }else{
        return 0;
    }
}

void dfs(int idx, int sum)
{
    int i;

    if(suc){
        return;
    }

    if(idx == 5){
        if(sum == target){
            suc = true;
        }
        return;
    }
    
    for(i = n - 1; i >= 0; --i){
        if(!visited[i]){
            visited[i] = 1;
            res[idx] = v[i];
            dfs(idx + 1, sum + mypow(-1, idx) * mypow(v[i], idx + 1));
            visited[i] = 0;

            if(suc){
                break;
            }
        }
    }
}

int main()
{
    int i;
    char str[1000];
    
    while(true){
        if(scanf("%d%s", &target, str) != 2){
            break;
        }else if(0 == target && strcmp(str, "END") == 0){
            break;
        }
        for(i = 0; str[i] != 0; ++i){
            v[i] = str[i] - 'A' + 1;
        }
        n = i;
        qsort(v, n, sizeof(int), comp);
        suc = false;
        for(i = 0; i < n; ++i){
            visited[i] = 0;
        }
        dfs(0, 0);
        if(suc){
            for(i = 0; i < 5; ++i){
                printf("%c", res[i] + 'A' - 1);
            }
            printf("\n");
        }else{
            printf("no solution\n");
        }
    }
    
    return 0;
}

