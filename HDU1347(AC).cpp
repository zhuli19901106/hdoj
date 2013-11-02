#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef struct st{
    int index;
    int count;
}st;

bool comparator(const st &a, const st &b)
{
    if(a.count == b.count){
        return a.index < b.index;
    }else{
        return a.count > b.count;
    }
}

int main()
{
    st a[10005];
    int m, n;
    int i, j;
    int tmp;
    
    while(scanf("%d%d", &n, &m) == 2){
        if(n == 0 && m == 0){
            break;
        }
        
        for(i = 0; i < 10005; ++i){
            a[i].index = i;
            a[i].count = 0;
        }
        
        for(i = 0; i < n; ++i){
            for(j = 0; j < m; ++j){
                scanf("%d", &tmp);
                ++(a[tmp].count);
            }
        }
        sort(a + 1, a + 10005, comparator);
        i = 2;
        while(a[i].count == a[1].count){
            ++i;
        }
        printf("%d", a[i].index);
        j = i + 1;
        while(a[j].count == a[i].count){
            printf(" %d", a[j].index);
            ++j;
        }
        printf("\n");
    }
    
    return 0;
}

