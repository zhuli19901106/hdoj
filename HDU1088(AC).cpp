#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main()
{
    char s[2000];
    int pos, len;
    int type;
    
    //freopen("C:/Users/hp/Documents/Visual Studio 2010/Projects/ZOJ/Debug/in.txt", "r", stdin);
    //freopen("C:/Users/hp/Documents/Visual Studio 2010/Projects/ZOJ/Debug/out.txt", "w", stdout);

    pos = 0;
    type = 1;
    while(scanf("%s", s) == 1){
        len = strlen(s);
        if(strcmp(s, "<br>") == 0){
            printf("\n");
            pos = 0;
            type = 1;
        }else if(strcmp(s, "<hr>") == 0){
            if(pos > 0){
                printf("\n");
                pos = 0;
            }
            printf("--------------------------------------------------------------------------------\n");
            pos = 0;
            type = 2;
        }else{
            if(type == 3){
                if(pos + len + 1 <= 80){
                    printf(" %s", s);
                    pos += len + 1;
                }else{
                    printf("\n%s", s);
                    pos = len;
                }
            }else{
                if(pos + len <= 80){
                    printf("%s", s);
                    pos += len;
                }else{
                    printf("\n%s", s);
                    pos = len;
                }
            }
            type = 3;
        }
    }
    printf("\n");
    
    return 0;
}

