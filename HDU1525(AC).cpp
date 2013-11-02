#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

void swap(int &a, int &b)
{
    int t;

    t = a;
    a = b;
    b = t;
}

int main()
{
    int a, b, ans;
    
    while(scanf("%d%d",&a,&b) == 2){
        if(a == b && a == 0){
            break;
        }
        
        ans = 0;
        if(a == 0 || b == 0 || a == b){
            goto end;
        }
        
        while(1)
        {
            if(a < b){
                swap(a,b);
            }
            if(a / b == 1){
                ans++;
                a -= b;
                continue;
            }
            if(a / b > 1){
                break;
            }
            if(a == 0 || b == 0){
                break;
            }
        }
end:
        if( ans % 2 == 0 )
            printf("Stan wins\n");
        else
            printf("Ollie wins\n");
    }
    
    return 0;
}

