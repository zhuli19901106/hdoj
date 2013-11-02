#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int b[11000];

int main()
{
    int i, j;
    int n;
    int count;

    memset(b, 0, 11000 * sizeof(int));
    b[0] = b[1] = 1;
    for(i = 2; i * i < 11000; ++i){
        if(b[i]){
            continue;
        }
        for(j = i; i * j < 11000; ++j){
            b[i * j] = 1;
        }
    }

    for(i = 0; i < 11000; ++i){
        b[i] = !b[i];
    }


    while(scanf("%d", &n) == 1 && n){
        count = 0;
        for(i = 2; i < n / 2; ++i){
            if(b[i] && b[n - i]){
                ++count;
            }
        }
        printf("%d\n", count);
    }

    return 0;
}

