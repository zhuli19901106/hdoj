#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int idx;
char s[1000];
int len;
bool suc;

void check(const char s[], int i)
{
    if(!suc){
        return;
    }

    if(i >= len || idx >= len){
        suc = false;
        return;
    }

    switch(s[i]){
    case 'p':
    case 'q':
    case 'r':
    case 's':
    case 't':
    case 'u':
    case 'v':
    case 'w':
    case 'x':
    case 'y':
    case 'z':
        idx = i + 1;
        return;
    case 'C':
    case 'D':
    case 'E':
    case 'I':
        idx = i + 1;
        check(s, idx);
        if(idx >= len){
            suc = false;
            return;
        }else{
            check(s, idx);
            return;
        }
    case 'N':
        idx = i + 1;
        check(s, idx);
        return;
    default:
        suc = false;
        return;
    }
}


int main()
{
    while(scanf("%s", s) == 1){
        len = strlen(s);
        idx = 0;
        suc = true;
        check(s, 0);

        if(idx != len){
            suc = false;
        }

        if(suc){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }

    return 0;
}

