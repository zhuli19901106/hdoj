#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

char s[100];
int main()
{
    int t, ti;

    while(scanf("%d", &t) == 1){
        for(ti = 0; ti < t; ++ti){
            scanf("%s", s);
            printf("6%s\n", s + 6);
        }
    }

    return 0;
}

