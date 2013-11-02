#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
    const int INF = 99999;
    int a[30][30];
    bool visited[30];
    int count_visited;
    int n, i, j;
    char lname[10];
    char rname[10];
    int nver;
    int dist;
    int min_dist;
    int min_ver;
    int min_cost;
    
    while(true){
        scanf("%d", &n);
        if(0 == n){
            break;
        }
        for(i = 0; i < 30; ++i){
            for(j = 0; j < 30; ++j){
                a[i][j] = 99999;
            }
        }
        for(i = 0; i < n - 1; ++i){
            scanf("%s%d", lname, &nver);
            for(j = 0; j < nver; ++j){
                scanf("%s%d", rname, &dist);
                a[lname[0] - 'A'][rname[0] - 'A'] = a[rname[0] - 'A'][lname[0] - 'A'] = dist;
            }
        }
        
        for(i = 0; i < n; ++i){
            visited[i] = false;
        }
        
        visited[0] = true;
        count_visited = 1;
        min_cost = 0;
        while(count_visited < n){
            min_dist = INF;
            min_ver = -1;
            for(i = 0; i < n; ++i){
                if(visited[i]){
                    for(j = 0; j < n; ++j){
                        if(a[i][j] < INF && !visited[j] && a[i][j] < min_dist){
                            min_ver = j;
                            min_dist = a[i][j];
                        }
                    }
                }
            }
            visited[min_ver] = true;
            ++count_visited;
            min_cost = min_cost + min_dist;
        }
        
        printf("%d\n", min_cost);
    }

    return 0;
}

