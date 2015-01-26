#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

__int64 gcd(__int64 a, __int64 b)
{
	while(true){
		if(a >= b){
			if(a % b){
				a = a % b;
			}else{
				return b;
			}
		}else{
			if(b % a){
				b = b % a;
			}else{
				return a;
			}
		}
	}
}

int main()
{
	char s[1000];
	int t, ti;
	int lp;
	__int64 a, b;
	__int64 n1, n2;
	int i;
	__int64 tmp;

	while(scanf("%d", &t) == 1){
		for(ti = 0; ti < t; ++ti){
			scanf("%s", s);
			lp = 0;
			while(s[lp] && s[lp] != '('){
				++lp;
			}
			if(!s[lp]){
				sscanf(&s[2], "%I64d", &a);
				n1 = 1;
				i = 2;
				while(s[i]){
					n1 *= 10;
					++i;
				}
				if(a){
					tmp = gcd(a, n1);
					a /= tmp;
					n1 /= tmp;
					printf("%I64d/%I64d\n", a, n1);
				}else{
					printf("0/1\n");
				}
			}else if(lp == 2){
				sscanf(&s[3], "%I64d", &b);
				i = lp + 1;
				n2 = 1;
				while(s[i] != ')'){
					n2 *= 10;
					++i;
				}
				--n2;
				if(a){
					tmp = gcd(b, n2);
					b /= tmp;
					n2 /= tmp;
					printf("%I64d/%I64d\n", b, n2);
				}else{
					printf("0/1\n");
				}
			}else{
				s[lp] = 0;
				sscanf(&s[2], "%I64d", &a);
				s[lp] = '(';
				i = 2;
				n1 = 1;
				while(s[i] != '('){
					n1 *= 10;
					++i;
				}
				sscanf(&s[lp + 1], "%I64d", &b);
				i = lp + 1;
				n2 = 1;
				while(s[i] != ')'){
					++i;
					n2 *= 10;
				}
				--n2;
				a = a * n2 + b;
				n1 = n1 * n2;
				if(a){
					tmp = gcd(a, n1);
					a /= tmp;
					n1 /= tmp;
					printf("%I64d/%I64d\n", a, n1);
				}else{
					printf("0/1\n");
				}
			}
		}
	}

	return 0;
}
