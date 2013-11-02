#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

void reverse(char s[], int left, int right)
{
    int i, j;
    char ch;

    i = left;
    j = right;
    while(i < j){
        ch = s[i];
        s[i] = s[j];
        s[j] = ch;
        ++i;
        --j;
    }
}

int main()
{
    char s[1500];
    int i, j, len;
    int t;

    while(gets(s) != NULL && sscanf(s, "%d", &t) == 1){
        while(t--){
            gets(s);
            len = strlen(s);
            i = 0;
            while(true){
                if(i >= len){
                    break;
                }
                while(i < len && s[i] == ' '){
                    ++i;
                }
                j = i;
                while(j < len && s[j] != ' '){
                    ++j;
                }
                --j;
                if(i < len){
                    reverse(s, i, j);
                    i = j + 1;
                }else{
                    break;
                }
            }
            puts(s);
        }
    }

    return 0;
}

