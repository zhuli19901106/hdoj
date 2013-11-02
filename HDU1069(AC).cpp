#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

typedef struct st{
    int x;
    int y;
    int z;
}st;

bool comparator(const st &a, const st &b)
{
    if(a.x == b.x){
        if(a.y == b.y){
            return a.z < b.z;
        }else{
            return a.y < b.y;
        }
    }else{
        return a.x < b.x;
    }
}

vector<st> v;
int n;
int f[500];

void myswap(int &a, int &b)
{
    int t;

    t = a;
    a = b;
    b = t;
}

const int mymax(const int a, const int b)
{
    return (a > b ? a : b);
}

const int mymin(const int a, const int b)
{
    return (a < b ? a : b);
}

int main()
{
    int i, j;
    int res;
    int ti;
    st b1, b2;

    ti = 0;
    while(scanf("%d", &n) == 1 && n){
        ++ti;
        memset(f, 0, 500 * sizeof(int));
        v.clear();
        for(i = 0; i < n; ++i){
            scanf("%d%d%d", &b1.x, &b1.y, &b1.z);

            b2.x = mymin(b1.x, b1.y);
            b2.y = mymax(b1.x, b1.y);
            b2.z = b1.z;
            v.push_back(b2);

            b2.x = mymin(b1.y, b1.z);
            b2.y = mymax(b1.y, b1.z);
            b2.z = b1.x;
            v.push_back(b2);

            b2.x = mymin(b1.z, b1.x);
            b2.y = mymax(b1.z, b1.x);
            b2.z = b1.y;
            v.push_back(b2);
        }
        sort(v.begin(), v.end(), comparator);
        n *= 3;
        for(i = 0; i < n; ++i){
            f[i] = v[i].z;
        }

        for(i = 1; i < n; ++i){
            for(j = 0; j < i; ++j){
                if(v[j].x < v[i].x && v[j].y < v[i].y){
                    f[i] = mymax(f[i], f[j] + v[i].z);
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

