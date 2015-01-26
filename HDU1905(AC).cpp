#define _CRT_SECURE_NO_WARNINGS
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

long long int p, a;

bool isprime(const long long int n)
{
	long long int i;
	long long int rt;

	rt = (long long int)sqrt(1.0 * n);
	for(i = 2; i <= rt; ++i){
		if(n % i == 0){
			return false;
		}
	}

	return true;
}

long long int mypow(long long int a, long long int n, long long int mod)
{
	long long int res;

	if(n == 0){
		return 1;
	}else if(n == 1){
		return a % mod;
	}else{
		if(n % 2){
			res = mypow(a, n / 2, mod);
			return a % mod * res % mod * res % mod;
		}else{
			res = mypow(a, n / 2, mod);
			return res % mod * res % mod;
		}
	}
}

int main()
{
	while(scanf("%lld%lld", &p, &a) == 2 && (p || a)){
		if(isprime(p)){
			printf("no\n");
		}else if(mypow(a, p, p) == a){
			printf("yes\n");
		}else{
			printf("no\n");
		}
	}

	return 0;
}
