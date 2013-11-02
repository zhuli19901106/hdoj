#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

char s[4][20];
char a[80][80];
int len[4];
int x1, y1, x2, y2;

int mymax(const int &a, const int &b)
{
    return (a > b ? a : b);
}

int main()
{
    int i, j;
    int ti;
    int maxlen1, maxlen2;

    ti = 0;
    while(scanf("%s", s[0]) == 1 && strcmp(s[0], "#") != 0){
        ++ti;
        if(ti > 1){
            printf("\n");
        }

        scanf("%s%s%s", &s[1], &s[2], &s[3]);
        for(i = 0; i < 4; ++i){
            len[i] = strlen(s[i]);
        }

        x1 = y1 = -1;
        for(i = 0; i < len[0]; ++i){
            for(j = 0; j < len[1]; ++j){
                if(s[0][i] == s[1][j]){
                    x1 = i;
                    y1 = j;
                    break;
                }
            }
            if(j != len[1]){
                break;
            }
        }
        if(x1 == -1 && y1 == -1){
            printf("Unable to make two crosses\n");
            continue;
        }

        x2 = y2 = -1;
        for(i = 0; i < len[2]; ++i){
            for(j = 0; j < len[3]; ++j){
                if(s[2][i] == s[3][j]){
                    x2 = i;
                    y2 = j;
                    break;
                }
            }
            if(j != len[3]){
                break;
            }
        }
        if(x2 == -1 && y2 == -1){
            printf("Unable to make two crosses\n");
            continue;
        }

        //The cross can be constructed
        memset(a, ' ', 80 * 80 * sizeof(char));
        maxlen1 = mymax(y1, y2);

        for(i = maxlen1; i > maxlen1 - y1; --i){
            a[i - 1][x1] = s[1][i - (maxlen1 - y1) - 1];
        }
        for(i = maxlen1; i > maxlen1 - y2; --i){
            a[i - 1][len[0] + 3 + x2] = s[3][i - (maxlen1 - y2) - 1];
        }

        for(i = 0; i < len[0]; ++i){
            a[maxlen1][i] = s[0][i];
        }
        for(i = 0; i < len[2]; ++i){
            a[maxlen1][len[0] + 3 + i] = s[2][i];
        }

        maxlen2 = mymax(len[1] - y1 - 1, len[3] - y2 - 1);
        for(i =    y1 + 1; i < len[1]; ++i){
            a[maxlen1 + (i - y1)][x1] = s[1][i];
        }
        for(i =    y2 + 1; i < len[3]; ++i){
            a[maxlen1 + (i - y2)][len[0] + 3 + x2] = s[3][i];
        }

        maxlen1 = maxlen1 + 1 + maxlen2;
        for(i = 0; i < maxlen1; ++i){
            j = 79;
            while(j >= 0 && a[i][j] == ' '){
                --j;
            }
            a[i][j + 1] = 0;
            printf("%s\n", a[i]);
        }
    }

    return 0;
}

