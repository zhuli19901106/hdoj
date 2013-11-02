#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

void swap_char(char &x, char &y)
{
    char t;
    
    t = x;
    x = y;
    y = t;
}

void reverse(char s[])
{
    int i, j;
    
    i = 0;
    j = strlen(s) - 1;
    while(i < j){
        swap_char(s[i], s[j]);
        ++i;
        --j;
    }
}

int main()
{
    char sa[1005];
    char sb[1005];
    char *pmin, *pmax;
    char sc[1005];
    int t, ti;
    int i;
    int lmax, lmin;
    
    while(true){
        if(scanf("%d", &t) != 1){
            break;
        }else{
            for(ti = 1; ti <= t; ++ti){
                memset(sa, 0, 1005 * sizeof(char));
                memset(sb, 0, 1005 * sizeof(char));
                memset(sc, 0, 1005 * sizeof(char));
                scanf("%s%s", sa, sb);
                reverse(sa);
                reverse(sb);
                lmin = strlen(sa);
                lmax = strlen(sb);
                if(lmin < lmax){
                    pmin = sa;
                    pmax = sb;
                }else{
                    pmin = sb;
                    pmax = sa;
                    lmin ^= lmax ^= lmin ^= lmax;
                }
                for(i = 0; i < lmax; ++i){
                    if(i < lmin){
                        sc[i] = (pmin[i] - '0') + (pmax[i] - '0');
                    }else{
                        sc[i] = pmax[i] - '0';
                    }
                }
                
                for(i = 0; i < 1004; ++i){
                    sc[i + 1] += sc[i] / 10;
                    sc[i] %= 10;
                }
                sc[1004] %= 10;
                
                i = 1004;
                while(i >= 0 && sc[i] == 0){
                    --i;
                }
                
                if(-1 == i){
                    sprintf(sc, "0");
                }else{
                    lmax = i + 1;
                    for(i = 0; i < lmax; ++i){
                        sc[i] += '0';
                    }
                    reverse(sa);
                    reverse(sb);
                    reverse(sc);
                }
                
                if(ti > 1){
                    printf("\n");
                }
                printf("Case %d:\n", ti);
                printf("%s + %s = %s\n", sa, sb, sc);
            }
        }
    }
    
    return 0;
}

