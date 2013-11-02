#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

typedef struct st{
    double p;
    double h;
}st;

bool comparator(const st &a, const st &b)
{
    if(a.p == b.p){
        return a.h > b.h;
    }else{
        return a.p < b.p;
    }
}

vector<st> vv;
int n;
double sum, res;

int main()
{
    st tmp;
    int i;
    int t, ti;

    while(scanf("%d", &t) == 1){
        for(ti = 0; ti < t; ++ti){
            scanf("%lf%d", &sum, &n);
            vv.clear();
            for(i = 0; i < n; ++i){
                scanf("%lf%lf", &tmp.p, &tmp.h);
                vv.push_back(tmp);
            }
            sort(vv.begin(), vv.end(), comparator);
            res = 0;
            for(i = 0; i < n; ++i){
                if(sum <= 0){
                    break;
                }
                if(sum >= vv[i].p * vv[i].h){
                    res += vv[i].h;
                    sum -= vv[i].p * vv[i].h;
                }else{
                    res += sum / vv[i].p;
                    sum = 0;
                }
            }

            printf("%.2f\n", res);
        }
    }

    return 0;
}

