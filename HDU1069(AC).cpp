#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

typedef struct Term {
    int x;
    int y;
    int z;
} Term;

bool comp(const Term &a, const Term &b)
{
    if (a.x != b.x) {
        return a.x < b.x;
    }
    if(a.y != b.y){
        return a.y < b.y;
    }
    return a.z < b.z;
}

const int N = 500;
vector<Term> v;
int n;
int f[N];

int main()
{
    int i, j;
    int res;
    int ti;
    Term b1, b2;
    
    ti = 0;
    while(scanf("%d", &n) == 1 && n){
        ++ti;
        memset(f, 0, N * sizeof(int));
        v.clear();
        for(i = 0; i < n; ++i){
            scanf("%d%d%d", &b1.x, &b1.y, &b1.z);
            
            b2.x = min(b1.x, b1.y);
            b2.y = max(b1.x, b1.y);
            b2.z = b1.z;
            v.push_back(b2);
            
            b2.x = min(b1.y, b1.z);
            b2.y = max(b1.y, b1.z);
            b2.z = b1.x;
            v.push_back(b2);

            b2.x = min(b1.z, b1.x);
            b2.y = max(b1.z, b1.x);
            b2.z = b1.y;
            v.push_back(b2);
        }
        sort(v.begin(), v.end(), comp);
        n *= 3;
        for(i = 0; i < n; ++i){
            f[i] = v[i].z;
        }
        
        for(i = 1; i < n; ++i){
            for(j = 0; j < i; ++j){
                if(v[j].x < v[i].x && v[j].y < v[i].y){
                    f[i] = max(f[i], f[j] + v[i].z);
                }
            }
        }
        
        res = f[0];
        for(i = 1; i < n; ++i){
            if(f[i] > res){
                res = f[i];
            }
        }
        
        printf("Case %d: maximum height = %d\n", ti, res);
    }
    
    return 0;
}