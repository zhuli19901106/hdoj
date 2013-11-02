#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

bool visited[30];
bool prime[50];
int p[30];

bool isprime(int n)
{
    int i;
    
    if(n <= 1){
        return false;
    }
    
    for(i = 2; i * i <= n; i++){
        if(n % i == 0){
            return false;
        }
    }
    
    return true;
}

void dfs(int cur, int end)
{
    int i;
    
    if(cur == end && prime[p[cur] + p[1]]){
        for(i = 1; i <= end; i++){
            if(i == 1){
                printf("%d", p[i]);
            }else{
                printf(" %d", p[i]);
            }
        }
        printf("\n");
    }
    
    for(i = 2; i <= end; i++){
        if(!visited[i] && prime[p[cur] + i]){
            visited[i] = true;
            p[cur + 1] = i;
            dfs(cur + 1, end);
            visited[i] = false;
        }
    }
}

int main()
{
    int case_no;
    int i;
    int n;
    
    for(i = 1; i < 50; i++){
        prime[i] = isprime(i);
    }
    
    p[1] = 1;
    visited[1] = 1;
    
    case_no = 0;
    while(scanf("%d", &n) == 1){
        ++case_no;
        printf("Case %d:\n", case_no);
        if(n % 2 == 0){
            dfs(1, n);
        }
        printf("\n");
    }
    
    return 0;
}

