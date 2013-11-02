#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int a[256];
char s[11000];

int main()
{
    int i;
    
    for(i = 0; i < 256; ++i){
        a[i] = i;
    }
    a['b'] = ' ';
    a['q'] = ',';
    a['t'] = '!';
    a['m'] = 'l';
    a['i'] = 'e';
    a['c'] = 'a';
    a['a'] = 'c';
    a['e'] = 'i';
    a['l'] = 'm';

    while(gets(s) != NULL){
        for(i = 0; s[i]; ++i){
            putchar(a[s[i]]);
        }
        putchar('\n');
    }

    return 0;
}

