#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
    int n;
    
    while(true){
        if(scanf("%d", &n) != 1){
            break;
        }else{
            printf("%d\n\n", (n % 2 ? (n + 1) / 2 * n : n / 2 * (n + 1)));
        }
    }
    
    return 0;
}

