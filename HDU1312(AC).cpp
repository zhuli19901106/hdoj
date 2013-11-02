#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

char a[22][22];
bool visited[22][22];
int w, h;
int si, sj;
int count;
int dx[4] = {-1, +1,  0,  0};
int dy[4] = { 0,  0, -1, +1};

void dfs(int x, int y)
{
    for(int i = 0; i < 4; ++i){
        if(a[x + dx[i]][y + dy[i]] == '.' && !visited[x + dx[i]][y + dy[i]]){
            visited[x + dx[i]][y + dy[i]] = true;
            count++;
            dfs(x + dx[i], y + dy[i]);
        }
    }
}

int main()
{
    int i, j;
    char str[100];

    while(true){
        if(scanf("%d%d", &w, &h) != 2){
            break;
        }else if(0 == w && 0 == h){
            break;
        }
        
        for(i = 0; i <= 21; ++i){
            for(j = 0; j <= 21; ++j){
                a[i][j] = '#';
                visited[i][j] = false;
            }
        }
        
        for(i = 1; i <= h; ++i){
            scanf("%s", str);
            for(j = 1; j <= w; ++j){
                if(str[j - 1] == '@'){
                    si = i;
                    sj = j;
                    a[i][j] = '.';
                }else{
                    a[i][j] = str[j - 1];
                }
            }
        }
        
        count = 1;
        visited[si][sj] = true;
        dfs(si, sj);

        printf("%d\n", count);
    }
    
    return 0;
}

