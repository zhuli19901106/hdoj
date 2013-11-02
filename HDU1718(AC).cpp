#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

typedef struct st{
    int id;
    int sc;
}st;
vector<st> v;

int main()
{
    int id, sc;
    int res;
    int i;
    st tmp;

    while(scanf("%d", &id) == 1){
        v.clear();
        while(scanf("%d%d", &tmp.id, &tmp.sc) == 2 && (tmp.id || tmp.sc)){
            if(tmp.id == id){
                sc = tmp.sc;
            }
            v.push_back(tmp);
        }
        
        res = 1;
        for(i = 0; i < (int)v.size(); ++i){
            if(v[i].sc > sc){
                ++res;
            }
        }

        printf("%d\n", res);
    }

    return 0;
}

