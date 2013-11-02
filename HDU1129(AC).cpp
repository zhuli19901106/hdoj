#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

char get_char(const int i)
{
    if(i == 0){
        return '_';
    }else if(i >= 1 && i <= 26){
        return 'a' + i - 1;
    }else if(i == 27){
        return '.';
    }else{
        return EOF;
    }
}

int get_code(const char ch)
{
    if(ch == '_'){
        return 0;
    }else if(ch >= 'a' && ch <= 'z'){
        return ch + 1 - 'a';
    }else if(ch == '.'){
        return 27;
    }else{
        return -1;
    }
}

int main()
{
    int cc[100];
    int pc[100];
    int p_c[100];
    int c_p[100];
    char cs[200];
    char ps[200];
    int k;
    int i;
    int n;

    while(scanf("%d", &k) && k){
        scanf("%s", cs);
        n = strlen(cs);
        for(i = 0; i < n; i++){
            cc[i] = get_code(cs[i]);
        }
        for(i = 0; i < n; i++){
            c_p[i] = k * i % n;
        }
        for(i = 0; i < n; i++){
            p_c[c_p[i]] = i;
        }
        for(i = 0; i < n; i++){
            pc[c_p[i]] = (cc[i] + i) % 28;
        }
        for(i = 0; i < n; i++){
            ps[i] = get_char(pc[i]);
        }
        ps[n] = 0;
        puts(ps);
    }

    return 0;
}

