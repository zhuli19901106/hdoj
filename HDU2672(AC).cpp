#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

char s[2000];

int main()
{
    int i, len;
    int f1, f2, f3;

    while(gets(s) != NULL){
        len = strlen(s);
        f1 = 0;
        f2 = 1;
        for(i = 0; i < len; ++i){
            if(s[i] >= 'A' && s[i] <= 'Z'){
                s[i] = (s[i] - 'A' + (f2)) % 26 + 'A';
                f3 = (f1 + f2) % 26;
                f1 = f2;
                f2 = f3;
            }
        }

        puts(s);
    }

    return 0;
}

