#define _CRT_SECURE_NO_WARNINGS
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int MAXN = 205;
double len[MAXN][MAXN];

inline double myabs(const double &a)
{
    return (a >= 0 ? a : -a);
}

int main()
{
    int x1, y1, x2, y2;
    int n;

    x1 = 0;
    y1 = 0;
    len[x1][y1] = 0;
    while(x1 + y1 <= 200){
        if(y1 == 0){
            y2 = x1 + 1;
            x2 = 0;
        }else{
            x2 = x1 + 1;
            y2 = y1 - 1;
        }
        len[x2][y2] = sqrt(1.0 * (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) + len[x1][y1];
        x1 = x2;
        y1 = y2;
    }

    while(scanf("%d", &n) == 1){
        while(n--){
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            printf("%.3f\n", myabs(len[x1][y1] - len[x2][y2]));
        }
    }

    return 0;
}

