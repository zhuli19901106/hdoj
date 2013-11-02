#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAXN = 6000;
char s[MAXN], t[MAXN];
char s1[MAXN], t1[MAXN];

void trim(char s[], char s1[])
{
    int i, j;

    i = 0;
    j = 0;
    while(s[i]){
        if(!(s[i] == ' ' || s[i] == '\t' || s[i] == '\n')){
            s1[j] = s[i];
            ++j;
        }
        ++i;
    }
    s1[j] = 0;
}

bool compare(char s1[], char s2[])
{
    int len1, len2;
    int i;

    len1 = strlen(s1);
    len2 = strlen(s2);
    if(len1 != len2){
        return false;
    }
    
    for(i = 0; i < len1; ++i){
        if(s1[i] != s2[i]){
            return false;
        }
    }

    return true;
}

int main()
{
    char str[MAXN];
    int n, ni;

    while(gets(str) != NULL && sscanf(str, "%d", &n) == 1){
        for(ni = 0; ni < n; ++ni){
            s[0] = 0;
            while(true){
                gets(str);
                if(strcmp(str, "START") == 0){
                    break;
                }
            }
            while(true){
                gets(str);
                if(strcmp(str, "END") == 0){
                    break;
                }else{
                    strcat(str, "\n");
                    strcat(s, str);
                }
            }

            t[0] = 0;
            while(true){
                gets(str);
                if(strcmp(str, "START") == 0){
                    break;
                }
            }
            while(true){
                gets(str);
                if(strcmp(str, "END") == 0){
                    break;
                }else{
                    strcat(str, "\n");
                    strcat(t, str);
                }
            }

            if(compare(s, t)){
                printf("Accepted\n");
            }else{
                trim(s, s1);
                trim(t, t1);
                if(compare(s1, t1)){
                    printf("Presentation Error\n");
                }else{
                    printf("Wrong Answer\n");
                }
            }
        }
    }

    return 0;
}

