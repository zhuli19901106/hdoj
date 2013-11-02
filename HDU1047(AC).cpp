#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

void GetDigits(int a[], char buffer[])
{
    int i;
    int j;
    int len;

    len = strlen(buffer);
    i = len - 1;
    j = 0;
    while(i >= 0 && j <= 1999){
        a[j] = buffer[i] - '0';
        ++j;
        --i;
    }
}

void PrintDigits(int digits[])
{
    int i;

    i = 1999;
    while(i >= 0 && digits[i] == 0){
        --i;
    }
    if(i == -1){
        printf("0");
    }else{
        while(i >= 0){
            printf("%c", digits[i] + '0');
            --i;
        }
    }
}

int main()
{
    int ni;
    int n, i;
    int a[2000];
    int sum[2000];
    char buffer[1000];

    while(true){
        if(scanf("%d", &n) != 1){
            break;
        }
        for(ni = 0; ni < n; ni++){
            memset(sum, 0, 2000 * sizeof(int));
            while(true){
                scanf("%s", buffer);
                if(strcmp(buffer, "0") == 0){
                    break;
                }else{
                    memset(a, 0, 2000 * sizeof(int));
                    GetDigits(a, buffer);
                    for(i = 0; i < 2000; i++){
                        sum[i] = sum[i] + a[i];
                    }

                    for(i = 0; i < 1999; i++){
                        sum[i + 1] += sum[i] / 10;
                        sum[i] %= 10;
                    }
                    sum[1999] %= 10;
                }
            }
            if(ni > 0){
                printf("\n");
            }
            PrintDigits(sum);
            printf("\n");
        }
    }

    return 0;
}

