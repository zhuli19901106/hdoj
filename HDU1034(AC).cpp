#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
    int n;
    int *a;
    int *b;
    int i;
    int step_count;
    
    while(true){
        if(scanf("%d", &n) == 1){
            if(n <= 0){
                break;
            }
            
            a = (int *)malloc(n * sizeof(int));
            b = (int *)malloc(n * sizeof(int));
            
            for(i = 0; i < n; i++){
                scanf("%d", &a[i]);
            }
            
            step_count = 0;
            while(true){
                for(i = 0; i < n; i++){
                    if(a[i] != a[(i + 1) % n]){
                        break;
                    }
                }
                if(i == n){
                    break;
                }else{
                    for(i = 0; i < n; i++){
                        b[(i + 1) % n] = a[i] / 2;
                    }
                    for(i = 0; i < n; i++){
                        a[i] = (a[i] / 2 + b[i] + 1) / 2 * 2;
                    }
                    step_count++;
                }
            }

            printf("%d %d\n", step_count, a[0]);
            
            free(a);
        }else{
            break;
        }
    }
    
    return 0;
}

