#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int n, m;
int res, sum;
int b[50001];
int prime[15000];
int pc;
int p[100];
int r[100];
int prc;

int ext_gcd(int a, int b, int &x, int &y)
{
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }else{
        int tmp = ext_gcd(b, a % b, y, x);
        y -= x * (a / b);
        return tmp;
    }
}

void mymultiply(int x)
{
    int i;

    for(i = 0; i < prc; ++i){
        while(x % p[i] == 0){
            ++r[i];
            x /= p[i];
        }
    }

    res = ((long long)res * x) % m;
    //watch out for integer ovverflow caused by multiplication
}

void mydivide(int x)
{
    int i;
    int pp, qq;

    for(i = 0; i < prc; ++i){
        while(x % p[i] == 0 && r[i] > 0){
            --r[i];
            x /= p[i];
        }
    }

    if(x > 1){
        ext_gcd(x, m, pp, qq);
        pp = (pp % m + m) % m;
        res = ((long long)res * pp) % m;
        //watch out for integer ovverflow caused by multiplication
    }
}

int main()
{
    int i, j, k;
    int t;

    memset(b, 0, 50001 * sizeof(int));
    b[0] = b[1] = 1;
    for(i = 2; i <= 50000 / i; ++i){
        if(b[i]){
            continue;
        }
        for(j = i; j <= 50000 / i; ++j){
            b[i * j] = 1;
        }
    }

    pc = 0;
    for(i = 0; i <= 50000; ++i){
        b[i] = !b[i];
        if(b[i]){
            prime[pc++] = i;
        }
    }

    while(scanf("%d%d", &n, &m) == 2 && (n || m)){
        if(m == 1){
            printf("0\n");
            continue;
        }

        //Factorization of m
        prc = 0;
        t = m;
        i = 0;
        while(prime[i] <= t / prime[i]){
            if(t % prime[i] == 0){
                p[prc++] = prime[i];
                while(t % prime[i] == 0){
                    t /= prime[i];
                }
            }
            ++i;
        }
        if(t > 1){
            p[prc++] = t;
            t = 1;
        }

        for(i = 0; i < prc; ++i){
            r[i] = 0;
        }
        sum = 1;
        res = 1;
        for(i = 2; i <= n; ++i){
            mymultiply(4 * i - 2);
            mydivide(i + 1);

            t = res;
            for(j = 0; j < prc; ++j){
                for(k = 0; k < r[j]; ++k){
                    t = ((long long)t * p[j]) % m;
                }
            }
            sum = (sum + t) % m;
        }

        printf("%d\n", sum);
    }

    return 0;
}

