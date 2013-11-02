#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

char a[10][10];
int len[10][10];
int di[4] = {-1, +1,  0,  0};
int dj[4] = { 0,  0, -1, +1};
bool visited[10][10];
bool success;
int n, m, t;
int starti, startj;
int doori, doorj;

int abs(int n)
{
    return (n >= 0 ? n : -n);
}

void dfs(int ci, int cj, int step_count)
{
    int i;

    if(success){
        return;
    }
    
    if(ci == doori && cj == doorj && step_count == t){
        success = true;
        return;
    }
    
    int tmp;
    
    tmp = t - step_count - abs(ci - doori) - abs(cj - doorj);
    if(tmp < 0 || tmp % 2 == 1){
        return;
    }
    
    for(i = 0; i < 4; ++i){
        if(
            a[ci + di[i]][cj + dj[i]] == '.'
            &&
            !visited[ci + di[i]][cj + dj[i]]
        ){
            visited[ci + di[i]][cj + dj[i]] = true;
            if(!success){
                dfs(ci + di[i], cj + dj[i], step_count + 1);
            }
            visited[ci + di[i]][cj + dj[i]] = false;
        }
    }
}

int main()
{
    int i, j;
    char str[100];
    
    while(true){
        if(scanf("%d%d%d", &n, &m, &t) != 3){
            break;
        }else if(0 == n && 0 == m && 0 == t){
            break;
        }
        
        for(i = 0; i <= n + 1; ++i){
            for(j = 0; j <= m + 1; ++j){
                a[i][j] = 'X';
            }
        }
        
        for(i = 0; i <= n + 1; ++i){
            for(j = 0; j <= m + 1; ++j){
                visited[i][j] = false;
            }
        }

        /*
        for(i = 1; i <= n; ++i){
            for(j = 1; j <= m; ++j){
                visited[i][j] = true;
            }
        }
        */
        
        for(i = 0; i <= n + 1; ++i){
            for(j = 0; j <= m + 1; ++j){
                len[i][j] = -1;
            }
        }
        
        for(i = 1; i <= n; i++){
            scanf("%s",str);
            for(j = 1; j <= m; j++){
                if(str[j - 1] == 'S'){
                    starti = i;
                    startj = j;
                    a[i][j] = '.';
                }else if(str[j - 1] == 'D'){
                    doori = i;
                    doorj = j;
                    a[i][j] = '.';
                }else{
                    a[i][j] = str[j - 1];
                }
            }
        }
        
        success = false;
        visited[starti][startj] = true;
        dfs(starti, startj, 0);
        visited[starti][startj] = false;
        
        if(success){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
    
    return 0;
}

