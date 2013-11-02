#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

char s[10];
int b[1000000];
int c[1000000];
int n, m;

int main()
{
    int i, j;

    memset(b, 0, 1000000 * sizeof(int));
    memset(c, 0, 1000000 * sizeof(int));
    for(i = 0; i < 1000000; ++i){
        sprintf(s, "%06d", i);
        for(j = 0; j < 6; ++j){
            if(s[j] == '6' && s[j + 1] == '2'){
                break;
            }
            if(s[j] == '4'){
                break;
            }
        }
        if(j == 6 && s[j] != '4'){
            b[i] = 1;
        }else{
            b[i] = 0;
        }
    }

    c[0] = b[0];
    for(i = 1; i < 1000000; ++i){
        c[i] = c[i - 1] + b[i];
    }

    while(scanf("%d%d", &n, &m) == 2 && (n || m)){
        if(n == 0){
            printf("%d\n", c[m]);
        }else{
            printf("%d\n", c[m] - c[n - 1]);
        }
    }
    
    return 0;
}

