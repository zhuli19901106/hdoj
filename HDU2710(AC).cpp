#define _CRT_SECURE_NO_WARNINGS
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAXN = 20000;
int b[MAXN + 1];
int idx[MAXN + 1];
int p[5000];
int pc;
int a;
int n;

void sieve_algorithm(int b[], int p[], int &pc)
{
    int i, j;

    memset(b, 0, (MAXN + 1) * sizeof(int));

    b[0] = b[1] = 1;
    for(i = 2; i * i <= MAXN; ++i){
        if(b[i]){
            continue;
        }
        for(j = i; j * i <= MAXN; ++j){
            b[j * i] = 1;
        }
    }

    pc = 0;
    for(i = 0; i <= MAXN; ++i){
        b[i] = !b[i];
        if(b[i]){
            p[pc++] = i;
        }
    }

    memset(idx, -1, (MAXN + 1) * sizeof(int));
    for(i = 0; i < pc; ++i){
        idx[p[i]] = i;
    }
    idx[0] = idx[1] = -1;
    i = 3;
    while(i <= MAXN){
        j = idx[i];
        while(i <= MAXN && idx[i + 1] == -1){
            idx[i + 1] = j;
            ++i;
        }
        ++i;
    }
}

int largest_prime_factor(int x)
{
    int i;

    if(x <= 1){
        return x;
    }else if(b[x]){
        return x;
    }

    i = idx[x];
    while(i >= 0){
        if(x % p[i] == 0){
            return p[i];
        }else{
            --i;
        }
    }

    return 1;
}

int main()
{
    int i;
    int rf, ri;
    int f;

    sieve_algorithm(b, p, pc);

    while(scanf("%d", &n) == 1){
        scanf("%d", &a);
        ri = a;
        rf = largest_prime_factor(a);
        for(i = 1; i < n; ++i){
            scanf("%d", &a);
            f = largest_prime_factor(a);
            if(f > rf){
                ri = a;
                rf = f;
            }
        }
        printf("%d\n", ri);
    }

    return 0;
}

