#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

char s[200];
char maxc;

int main()
{
    int i;

    while(gets(s) != NULL){
        i = 0;
        while(true){
            while(s[i] && s[i] == ' '){
                ++i;
            }
            if(!s[i]){
                break;
            }
            if(s[i] >= 'a' && s[i] <= 'z'){
                s[i] = s[i] - 'a' + 'A';
            }
            while(s[i] && s[i] != ' '){
                ++i;
            }
            if(!s[i]){
                break;
            }
        }
        puts(s);
    }

    return 0;
}

