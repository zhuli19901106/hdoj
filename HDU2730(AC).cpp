#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int n;
int a[100];
int g;
int res;

bool comparator(const int &a, const int &b)
{
    return a > b;
}

int main()
{
    int i;
    int maxi;
    int tmp;
    int x, y, z;

    while(scanf("%d", &n) == 1 && n){
        memset(a, 0, 100 * sizeof(int));
        for(i = 0; i < n; ++i){
            scanf("%d", &a[i]);
        }
        scanf("%d", &g);
        maxi = 0;
        for(i = 1; i < n; ++i){
            if(a[i] > a[maxi]){
                maxi = i;
            }
        }
        tmp = (a[maxi] + 49) / 50 * 50;
        res = tmp / 50;
        for(i = 0; i < n; ++i){
            a[i] = tmp - a[i];
        }

        while(g > 0){
            while(g > 0){
                x = 0;
                while(x < n && !a[x]){
                    ++x;
                }
                if(x >= n){
                    break;
                }

                y = x + 1;
                while(y < n && !a[y]){
                    ++y;
                }
                if(y >= n){
                    break;
                }

                z = y + 1;
                while(z < n && !a[z]){
                    ++z;
                }
                if(z >= n){
                    break;
                }

                --a[x];
                --a[y];
                --a[z];
                --g;
                sort(a, a + n, comparator);
            }
            if(g > 0){
                ++res;
                for(i = 0; i < n; ++i){
                    a[i] += 50;
                }
            }
        }

        printf("%d\n", res);
    }

    return 0;
}

