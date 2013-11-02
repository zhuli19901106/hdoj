#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int n, l;
int a[50];
int b[50];

int dfs(int index, int sum, int mark)
{
    int i;
    int res;

    if(mark >= 5){
        return true;
    }

    if(sum == l){
        return dfs(0, 0, mark + 1);
    }

    for(i = index; i < n; ++i){
        if(!b[i] && sum + a[i] <= l){
            b[i] = mark;
            res = dfs(i + 1, sum + a[i], mark);
            if(!res){
                b[i] = 0;
            }else{
                return true;
            }
        }
    }

    return false;
}

bool comparator(const int &a, const int &b)
{
    return a > b;
}

int main()
{
    int t, ti;
    int i;

    while(scanf("%d", &t) == 1){
        for(ti = 0; ti < t; ++ti){
            memset(a, 0, 50 * sizeof(int));
            l = 0;
            scanf("%d", &n);
            for(i = 0; i < n; ++i){
                scanf("%d", &a[i]);
                l += a[i];
            }
            sort(a, a + n, comparator);

            if(l % 4){
                printf("no\n");
                continue;
            }else{
                l = l / 4;
            }

            memset(b, 0, 50 * sizeof(int));
            if(dfs(0, 0, 1)){
                printf("yes\n");
            }else{
                printf("no\n");
            }
        }
    }

    return 0;
}

