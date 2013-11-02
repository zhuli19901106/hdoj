#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
    int a, b;
    
    while(true){
        if(scanf("%d%d", &a, &b) != 2){
            break;
        }else{
            printf("%d\n", a + b);
        }
    }
    
    return 0;
}

