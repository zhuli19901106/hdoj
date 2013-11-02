#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int n, m;

inline bool isleap(const int &n)
{
    return (n % 100 == 0 ? n % 400 == 0 : n % 4 == 0);
}

int main()
{
    int t;

    while(scanf("%d", &t) == 1){
        while(t--){
            scanf("%d%d", &n, &m);
            while(true){
                if(isleap(n)){
                    --m;
                    if(m <= 0){
                        break;
                    }
                    n += 4;
                }else{
                    if(n % 4){
                        n = (n + 3) / 4 * 4;
                    }else{
                        n += 4;
                    }
                }
            }
            printf("%d\n", n);
        }
    }

    return 0;
}

