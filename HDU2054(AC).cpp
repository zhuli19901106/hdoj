#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAXN = 1000005;
char sa[MAXN], st[MAXN], sb[MAXN];
bool ssa, ssb;

void process(char t[], char s[], bool &ss)
{
    int dp;
    int len;
    int i, j;
    int left;

    len = strlen(t);
    for(i = 0; i < len; ++i){
        if(t[i] >= '1' && t[i] <= '9'){
            break;
        }
    }
    if(i == len){
        sprintf(s, "0");
        ss = true;
        return;
    }

    if(t[0] == '-'){
        ss = false;
    }else{
        ss = true;
    }

    for(i = 0; i < len; ++i){
        if(t[i] == '.'){
            break;
        }
    }
    dp = i;

    if(t[0] >= '0' && t[0] <= '9'){
        left = 0;
    }else{
        left = 1;
    }
    for(i = left; i < dp; ++i){
        if(t[i] >= '1' && t[i] <= '9'){
            break;
        }
    }

    j = 0;
    while(i < dp){
        s[j++] = t[i++];
    }
    if(dp == len){
        s[j] = 0;
    }else{
        s[j++] = '.';
        ++i;
        while(i < len){
            s[j++] = t[i++];
        }
        while(s[j - 1] == '0'){
            s[--j] = 0;
        }
        if(s[j - 1] == '.'){
            s[--j] = 0;
        }else{
            s[j] = 0;
        }
    }
}

int main()
{
    while(scanf("%s%s", sa, sb) == 2){
        memcpy(st, sa, MAXN * sizeof(char));
        process(st, sa, ssa);
        memcpy(st, sb, MAXN * sizeof(char));
        process(st, sb, ssb);

        /*
        printf("sa: %s\n", sa);
        printf("sb: %s\n", sb);
        */

        if(strcmp(sa, sb) == 0 && ssa == ssb){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }

    return 0;
}

