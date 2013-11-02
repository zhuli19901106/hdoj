#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

char s[100];
int m;

int main()
{
    int i, j;
    bool suc;
    bool b[4];

    while(gets(s) != NULL && sscanf(s, "%d", &m) == 1){
        for(i = 0; i < m; ++i){
            gets(s);
            j = strlen(s);
            suc = true;
            if(j < 8 || j > 16){
                suc = false;
            }

            b[0] = b[1] = b[2] = b[3] = false;
            for(j = 0; s[j]; ++j){
                if(s[j] >= 'A' && s[j] <= 'Z'){
                    b[0] = true;
                }else if(s[j] >= 'a' && s[j] <= 'z'){
                    b[1] = true;
                }else if(s[j] >= '0' && s[j] <= '9'){
                    b[2] = true;
                }else if(
                    s[j] == '~' ||
                    s[j] == '!' ||
                    s[j] == '@' ||
                    s[j] == '#' ||
                    s[j] == '$' ||
                    s[j] == '%' ||
                    s[j] == '^'){
                    b[3] = true;
                }
            }
            j = 0;
            if(b[0]){
                ++j;
            }
            if(b[1]){
                ++j;
            }
            if(b[2]){
                ++j;
            }
            if(b[3]){
                ++j;
            }
            if(j < 3){
                suc = false;
            }
            if(suc){
                printf("YES\n");
            }else{
                printf("NO\n");
            }
        }
    }

    return 0;
}

