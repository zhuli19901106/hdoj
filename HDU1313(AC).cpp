#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

void reverse(char s[])
{
    int i;
    int len;
    char t;

    len = strlen(s);
    i = 0;
    while(i < len - 1 - i){
        t = s[i];
        s[i] = s[len - 1 - i];
        s[len - 1 - i] = t;
        ++i;
    }
}

int main()
{
    char s[1000];
    char t[1000];
    char loop[1000];
    int i, j, k, n;
    
    while(scanf("%s", s) == 1){
        n = strlen(s);
        reverse(s);
        strcpy(loop, s);
        strcat(loop, s);
        loop[2 * n - 1] = 0;
        for(i = 0; i < n; ++i){
            t[i] = s[i];
        }
        t[i] = 0;
        for(i = 1; i < n; ++i){
            for(j = 0; j < n; ++j){
                t[j] = (s[j] - '0') + (t[j] - '0');
            }
            for(j = 0; j < n; ++j){
                t[j + 1] += t[j] / 10;
                t[j] %= 10;
                t[j] += '0';
            }
            if(t[n]){
                //overflow, not cyclic
                break;
            }else{
                for(j = 0; j < n; ++j){
                    for(k = 0; k < n; ++k){
                        if(t[k] != loop[j + k]){
                            break;
                        }
                    }
                    if(k == n){
                        break;
                    }
                }
                if(j == n){
                    //no match, not cyclic
                    break;
                }
            }
        }
        reverse(s);
        if(i == n){
            printf("%s is cyclic\n", s);
        }else{
            printf("%s is not cyclic\n", s);
        }
    }
    
    return 0;
}

