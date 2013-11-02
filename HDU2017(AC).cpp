#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main()
{
    char s[1000];
    int n, ni, i;
    int res;

    while(gets(s) != NULL){
        sscanf(s, "%d", &n);
        for(ni = 0; ni < n; ++ni){
            gets(s);
            res = 0;
            for(i = 0; s[i]; ++i){
                if(s[i] >= '0' && s[i] <= '9'){
                    ++res;
                }
            }
            printf("%d\n", res);
        }
    }

    return 0;
}

