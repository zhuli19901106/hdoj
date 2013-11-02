#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int v[4] = {25, 10, 5, 1};
int n[4];
int c[4];
bool success;

void dfs(int sum, int idx)
{
    int i;
    int up;
    
    if(idx >= 4 && sum > 0){
        return;
    }
    if(success){
        return;
    }
    if(sum == 0){
        if(idx < 4){
            for(i = idx; i < 4; ++i){
                c[i] = 0;
            }
        }
        
        for(i = 0; i < 4; ++i){
            if(i == 0){
                printf("%d", c[i]);
            }else{
                printf(" %d", c[i]);
            }
        }
        printf("\n");
        success = true;

        return;
    }
    up = sum / v[idx];
    if(n[idx] < up){
        up = n[idx];
    }
    for(i = up; i >= 0; --i){
        c[idx] = i;
        dfs(sum - i * v[idx], idx + 1);
    }
}

int main()
{
    double d;
    int sum;
    
    while(true){
        if(scanf("%lf%d%d%d%d", &d, &n[0], &n[1], &n[2], &n[3]) != 5){
            break;
        }
        sum = (int)(d * 100 + 0.5);
        success = false;
        memset(c, 0, 4 * sizeof(int));
        dfs(sum, 0);
        if(!success){
            printf("NO EXACT CHANGE\n");
        }
    }
    
    return 0;
}

