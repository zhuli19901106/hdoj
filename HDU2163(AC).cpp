#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main()
{
    char s[1000];
    int len, i, j;

    j = 0;
    while(scanf("%s", s) == 1 && strcmp(s, "STOP")){
        ++j;
        len = strlen(s);
        i = 0;
        while(i < len - 1 - i){
            if(s[i] == s[len - 1 - i]){
                ++i;
            }else{
                break;
            }
        }

        if(i >= len - 1 - i){
            printf("#%d: YES\n", j);
        }else{
            printf("#%d: NO\n", j);
        }
    }

    return 0;
}

