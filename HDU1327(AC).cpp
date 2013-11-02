#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

void sort(char a[], int n)
{
    int i, j;
    char tmp;

    for(i = 0; i < n - 1; i++){
        for(j = i + 1; j < n; j++){
            if(a[i] > a[j]){
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
}

int find(char a[], int n, int key)
{
    int i;

    for(i = 0; i < n; i++){
        if(a[i] == key){
            return i;
        }
    }

    return -1;
}

int main()
{
    int i;
    int j;
    int n;
    int c;
    int pos;
    char str[1000];
    char a[100];
    char dst;
    char src;

    int casecount;

    casecount = 0;
    while(true){
        c = 0;
        a[c] = 'a';
        c++;
        gets(str);
        sscanf(str, "%d", &n);
        if(n == 0){
            break;
        }else{
            casecount++;
        }

        for(i = 0; i < n; i++){
            gets(str);
            sscanf(str, "%c = %c", &dst, &src);
            pos = find(a, c, src);
            if(pos != -1){
                pos = find(a, c, dst);
                if(pos == -1){
                    a[c] = dst;
                    c++;
                }
            }else{
                pos = find(a, c, dst);
                if(pos != -1){
                    for(j = pos + 1; j < c; j++){
                        a[j - 1] = a[j];
                    }
                    c--;
                }
            }
        }
        sort(a, c);

        printf("Program #%d\n", casecount);
        if(c == 0){
            printf("none");
            printf("\n\n");
        }else{
            for(i = 0; i < c; i++){
                printf("%c ", a[i]);
            }
            printf("\n\n");
        }
    }

    return 0;
}

