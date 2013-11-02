#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

bool isprime(int n)
{
    int i;
    
    if(n <= 1){
        return false;
    }else{
        for(i = 2; i * i <= n; ++i){
            if(n % i == 0){
                return false;
            }
        }
        
        return true;
    }
}

void get_digits(char s[], int a[], int maxlen)
{
    int digit_count;
    int i;
    int j;
    int t;
    
    digit_count = 0;
    memset(a, 0, maxlen * sizeof(int));
    for(i = 0; s[i] != 0; ++i){
        if(s[i] == ','){
            ++digit_count;
        }
    }
    
    j = 0;
    i = digit_count;
    while(true){
        t = 0;
        while(s[j] != ',' && s[j] != 0){
            if(s[j] >= '0' && s[j] <= '9'){
                t = t * 10 + (s[j] - '0');
            }
            ++j;
        }
        a[i--] = t;
        if(i < 0 || s[j] == 0){
            break;
        }
        while(s[j] == ','){
            ++j;
        }
    }
}

bool is_zero(int a[])
{
    int i;

    i = 29;
    while(i >= 0 && a[i] == 0){
        --i;
    }

    return i < 0;
}

int main()
{
    int radix[30];
    int ax[30], ay[30], az[30];
    char sx[1000], sy[1000];
    int len;
    int i;
    
    len = 0;
    i = 2;
    while(len < 30){
        if(isprime(i)){
            radix[len++] = i;
        }
        ++i;
    }
    
    while(true){
        if(scanf("%s%s", sx, sy) != 2){
            break;
        }
        memset(ax, 0, 30 * sizeof(int));
        memset(ay, 0, 30 * sizeof(int));
        
        get_digits(sx, ax, 30);
        get_digits(sy, ay, 30);

        if(is_zero(ax) || is_zero(ay)){
            break;
        }

        memset(az, 0, 30 * sizeof(int));
        for(i = 0; i < 30; ++i){
            az[i] = ax[i] + ay[i];
        }
        
        for(i = 0; i < 30; ++i){
            az[i + 1] += az[i] / radix[i];
            az[i] %= radix[i];
        }
        az[29] %= radix[29];
        
        for(i = 29; i >= 0; --i){
            if(az[i] != 0){
                break;
            }
        }
        
        if(i == -1){
            printf("0\n");
        }else{
            printf("%d", az[i]);
            while((--i) >= 0){
                printf(",%d", az[i]);
            }
            printf("\n");
        }
    }
    
    return 0;
}

