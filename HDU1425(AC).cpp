#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;

bool comparator(const int &a, const int &b)
{
    return a > b;
}

int n, m;
int a[1000005];

int main()
{
    int i;

    while(scanf("%d%d", &n, &m) == 2){
        for(i = 0; i < n; ++i){
            scanf("%d", &a[i]);
        }
        sort(a, a + n, comparator);
        for(i = 0; i < m; ++i){
            printf((i > 0 ? " %d" : "%d"), a[i]);
        }
        printf("\n");
    }

    return 0; 
}

