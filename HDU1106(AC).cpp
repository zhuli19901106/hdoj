#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

char s[1200];
int len;
int a[1200];
int n;

int main()
{
    int i;

    while(gets(s) != NULL){
        len = strlen(s);
        for(i = 0; i < len; ++i){
            if(s[i] == '5'){
                s[i] = ' ';
            }
        }
        i = 0;
        n = 0;
        while(true){
            if(i >= len){
                break;
            }
            while(i < len && s[i] == ' '){
                ++i;
            }
            if(i >= len){
                break;
            }
            sscanf(s + i, "%d", &a[n]);
            ++n;
            while(i < len && s[i] != ' '){
                ++i;
            }
        }
        sort(a, a + n);
        for(i = 0; i < n; ++i){
            if(i == 0){
                printf("%d", a[i]);
            }else{
                printf(" %d", a[i]);

            }
        }
        printf("\n");
    }

    return 0;
}

