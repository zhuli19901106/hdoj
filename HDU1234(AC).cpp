#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

typedef struct st{
    string s;
    int t1;
    int t2;
}st;
vector<st> vv;
int n;
int i1, i2;

int main()
{
    char str[1000];
    int h, m , s;
    int t, ti;
    int i;

    while(scanf("%d", &t) == 1){
        for(ti = 0; ti < t; ++ti){
            vv.clear();
            scanf("%d", &n);            
            for(i = 0; i < n; ++i){
                vv.push_back(st());
                scanf("%s", str);
                vv[i].s = string(str);
                scanf("%02d%*1s%02d%*1s%02d", &h, &m, &s);
                vv[i].t1 = h * 3600 + m * 60 + s;
                scanf("%02d%*1s%02d%*1s%02d", &h, &m, &s);
                vv[i].t2 = h * 3600 + m * 60 + s;
            }

            i1 = 0;
            for(i = 1; i < n; ++i){
                if(vv[i].t1 < vv[i1].t1){
                    i1 = i;
                }
            }

            i2 = 0;
            for(i = 1; i < n; ++i){
                if(vv[i].t2 > vv[i2].t2){
                    i2 = i;
                }
            }

            printf("%s %s\n", vv[i1].s.data(), vv[i2].s.data());
            vv.clear();
        }
    }

    return 0;
}

