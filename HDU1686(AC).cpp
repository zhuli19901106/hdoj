#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

char pat[10005];
char word[1000005];
int next[10005];
int lp, lw;

void get_next()
{  
    int i = 0;
    int j = -1;

    memset(next, 0, 10005 * sizeof(int));
    next[0] = -1;
    while(i <= lp - 1){
        if(j == -1 || pat[i] == pat[j]){
            ++i;
            ++j;
            next[i] = j;
        }else{
            j = next[j];
        }
    }
}

int count_kmp()
{
    int index;
    int pos;
    int count;

    count = index = pos = 0;
    while(index <= lw - 1){
        if(pos == -1 || word[index] == pat[pos]){
            ++index;
            ++pos;
        }else{
            pos = next[pos];
        }

        if(pos == lp){
            ++count;
        }
    }

    return count;
}

int main()
{
    int c;
    int t, ti;

    if(scanf("%d", &t) == 1){
        for(ti = 0; ti < t; ++ti){
            memset(pat, 0, 10005 * sizeof(char));
            memset(word, 0, 1000005 * sizeof(char));
            scanf("%s", pat);
            scanf("%s", word);
            
            lp = 0;
            while(pat[lp]){
                ++lp;
            }
            lw = 0;
            while(word[lw]){
                ++lw;
            }

            get_next();
            c = count_kmp();
            printf("%d\n", c);
        }
    }

    return 0;
}

