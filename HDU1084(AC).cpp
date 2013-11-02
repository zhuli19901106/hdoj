#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

typedef struct st{
    int p;
    int t;
    int score;
}st;
const int sc[6][2] = {{50, 50}, {65, 60}, {75, 70}, {85, 80}, {95, 90}, {100, 100}};
vector<int> v[6];
vector<st> vv;
int n;

bool comparator(const int &a, const int &b)
{
    return vv[a].t < vv[b].t;
}

int main()
{
    st tmp;
    int i, j;
    int x, y, z;

    while(scanf("%d", &n) == 1 && n >= 0){
        vv.clear();
        for(i = 0; i < 6; ++i){
            v[i].clear();
        }
        for(i = 0; i < n; ++i){
            scanf("%d", &tmp.p);
            scanf("%02d%*1s%02d%*1s%02d", &x, &y, &z);
            tmp.t = x * 3600 + y * 60 + z;
            vv.push_back(tmp);
            v[tmp.p].push_back(vv.size() - 1);
        }
        for(i = 0; i < 6; ++i){
            sort(v[i].begin(), v[i].end(), comparator);
        }

        int len;
        for(i = 0; i < 6; ++i){
            len = (int)v[i].size();
            for(j = 0; j < len / 2; ++j){
                vv[v[i][j]].score = sc[i][0];
            }
            for(j = len / 2; j < len; ++j){
                vv[v[i][j]].score = sc[i][1];
            }
        }

        for(i = 0; i < (int)vv.size(); ++i){
            printf("%d\n", vv[i].score);
        }
        printf("\n");
    }

    return 0;
}

