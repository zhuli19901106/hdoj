#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

char s[2000];
int a, b;

int main()
{
    int i, len;

    while(scanf("%s%d", s, &b) == 2){
        len = strlen(s);
        a = 0;
        for(i = 0; s[i]; ++i){
            a = (a * 10 + (s[i] - '0')) % b;
        }
        printf("%d\n", a);
    }

    return 0;
}

