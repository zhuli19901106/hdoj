#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAXN = 200;
int a[MAXN];
int al;
int b[MAXN];
int bl;
int f[500][MAXN];
int fl[500];

int main()
{
    int i, j, x, y;
    char sa[1000], sb[1000];

    memset(f, 0, 500 * sizeof(int));
    f[0][0] = 1;
    f[1][0] = 1;
    for(i = 2; i <= 499; ++i){
        for(j = 0; j < MAXN; ++j){
            f[i][j] = f[i - 1][j] + f[i - 2][j];
        }
        for(j = 0; j < MAXN - 1; ++j){
            f[i][j + 1] += f[i][j] / 10;
            f[i][j] %= 10;
        }
        f[i][MAXN - 1] %= 10;
    }

    fl[0] = 1;
    for(i = 1; i <= 499; ++i){
        j = MAXN - 1;
        while(j >= 0 && !f[i][j]){
            --j;
        }
        fl[i] = j + 1;
    }

    while(scanf("%s%s", sa, sb) == 2 && (strcmp(sa, "0") || strcmp(sb, "0"))){
        if(strcmp(sa, "0") == 0){
            sa[0] = '1';
        }
        al = strlen(sa);
        memset(a, 0, MAXN * sizeof(int));
        for(i = 0; i <= al - 1; ++i){
            a[al - 1 - i] = sa[i] - '0';
        }

        bl = strlen(sb);
        memset(b, 0, MAXN * sizeof(int));
        for(i = 0; i <= bl - 1; ++i){
            b[bl - 1 - i] = sb[i] - '0';
        }

        for(i = 1; i <= 499; ++i){
            if(fl[i] < al){
                continue;
            }else if(fl[i] == al){
                for(j = MAXN - 1; j >= 0; --j){
                    if(f[i][j] > a[j]){
                        j = MAXN;
                        break;
                    }else if(f[i][j] == a[j]){
                        continue;
                    }else{
                        j = -2;
                        break;
                    }
                }
                if(j == MAXN || j == -1){
                    x = i;
                    break;
                }
            }else{
                x = i;
                break;
            }
        }

        for(i = 499; i >= 1; --i){
            if(fl[i] > bl){
                continue;
            }else if(fl[i] == bl){
                for(j = MAXN - 1; j >= 0; --j){
                    if(f[i][j] > b[j]){
                        j = MAXN;
                        break;
                    }else if(f[i][j] == b[j]){
                        continue;
                    }else{
                        j = -2;
                        break;
                    }
                }
                if(j == -2 || j == -1){
                    y = i;
                    break;
                }
            }else{
                y = i;
                break;
            }
        }

        printf("%d\n", y - x + 1);
    }

    return 0;
}

