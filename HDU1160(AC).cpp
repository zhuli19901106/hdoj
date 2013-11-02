#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef struct st{
    int w;
    int s;
    int i;
}st;

bool comparator(const st &a, const st &b)
{
    if(a.w == b.w){
        return a.s < b.s;
    }else{
        return a.w > b.w;
    }
}

const int MAXN = 1005;
st a[MAXN];
int len[MAXN], maxlen;
int last[MAXN];
int n;

int main()
{
    int i, j;
    st tmp;

    n = 1;
    while(scanf("%d%d", &tmp.w, &tmp.s) == 2){
        tmp.i = n;
        a[n] = tmp;
        ++n;
    }
    sort(a + 1, a + n + 1, comparator);

    maxlen = 0;
    memset(len, 0, MAXN * sizeof(int));
    memset(last, 0, MAXN * sizeof(int));
    for(i = 1; i <= n; ++i){
        len[i] = 1;
        if(len[i] > maxlen){
            maxlen = len[i];
        }
        last[i] = i;
        for(j = 1; j < i; ++j){
            if(a[j].w > a[i].w && a[j].s < a[i].s && len[j] + 1 > len[i]){
                len[i] = len[j] + 1;
                last[i] = j;
                if(len[i] > maxlen){
                    maxlen = len[i];
                }
            }
        }
    }

    for(i = 1; i <= n; ++i){
        if(len[i] == maxlen){
            break;
        }
    }

    printf("%d\n", maxlen);
    while(i != last[i]){
        printf("%d\n", a[i].i);
        i = last[i];
    }
    printf("%d\n", a[i].i);

    return 0;
}

