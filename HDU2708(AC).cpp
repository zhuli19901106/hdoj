#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int n;
char s[1000];
int a[26];

int main()
{
    int i, j, k;
    int maxa;

    while(true){
        for(i = 0; i < 26; ++i){
            a[i] = 0;
        }
        for(i = 0; i < 4; ++i){
            if(gets(s) != NULL){
                for(j = 0; s[j]; ++j){
                    if(s[j] >= 'A' && s[j] <= 'Z'){
                        ++a[s[j] - 'A'];
                    }
                }
            }else{
                break;
            }
        }
        if(i == 4){
            maxa = a[0];
            for(i = 1; i < 26; ++i){
                if(a[i] > maxa){
                    maxa = a[i];
                }
            }
            for(i = maxa; i > 0; --i){
                memset(s, ' ', 1000 * sizeof(char));
                k = 0;
                for(j = 0; j < 26; ++j){
                    s[k++] = ' ';
                    if(a[j] >= i){
                        s[k++] = '*';
                    }else{
                        s[k++] = ' ';
                    }
                }
                j = 999;
                while(j > 1 && s[j] == ' '){
                    --j;
                }
                s[j + 1] = 0;
                puts(s + 1);
            }
            memset(s, ' ', 1000 * sizeof(char));
            k = 0;
            for(i = 0; i < 26; ++i){
                s[k++] = ' ';
                s[k++] = 'A' + i;
            }
            i = 999;
            while(i > 1 && s[i] == ' '){
                --i;
            }
            s[i + 1] = 0;
            puts(s + 1);
        }else{
            break;
        }
    }

    return 0;
}

