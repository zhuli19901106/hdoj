#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;


vector<int> v;
int n;

int main()
{
    int t, ti;
    int i;

    while(scanf("%d", &t) == 1){
        for(ti = 0; ti < t; ++ti){
            v.clear();
            scanf("%d", &n);
            while(true){
                if(n == 1){
                    break;
                }
                if(n % 2){
                    v.push_back(n);
                    n = 3 * n + 1;
                }else{
                    n = n / 2;
                }
            }

            if(v.size() > 0){
                printf("%d", v[0]);
                for(i = 1; i < (int)v.size(); ++i){
                    printf(" %d", v[i]);
                }
                printf("\n");
            }else{
                printf("No number can be output !\n");
            }
        }
    }

    return 0;
}

