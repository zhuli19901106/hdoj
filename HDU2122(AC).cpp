#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

typedef struct st{
    int a;
    int b;
    int c;
}st;

bool comparator(const st &x, const st &y)
{
    return x.c < y.c;
}

vector<st> v;
int n, m;
int res;
int dj[1005];

int find_root(int x)
{
    int r, k;

    r = x;
    while(dj[r] != r){
        r = dj[r];
    }

    k = x;
    while(x != r){
        x = dj[x];
        dj[k] = r;
        k = x;
    }

    return r;
}

int main()
{
    int i;
    int cc;
    int ra, rb;
    st tmp;

    while(scanf("%d%d", &n, &m) == 2){
        v.clear();

        for(i = 0; i < m; ++i){
            scanf("%d%d%d", &tmp.a, &tmp.b, &tmp.c);
            v.push_back(tmp);
        }
        if(n == 1){
            printf("0\n\n");
            continue;
        }
        sort(v.begin(), v.end(), comparator);

        cc = 0;
        res = 0;

        for(i = 0; i < n; ++i){
            dj[i] = i;
        }

        for(i = 0; i < m; ++i){
            ra = find_root(v[i].a);
            rb = find_root(v[i].b);
            if(ra != rb){
                dj[ra] = rb;
                res += v[i].c;
                find_root(v[i].a);
                find_root(v[i].b);
                ++cc;
            }
            if(cc >= n - 1){
                break;
            }
        }

        if(cc >= n - 1){
            printf("%d\n\n", res);
        }else{
            printf("impossible\n\n");
        }
    }

    return 0;
}

