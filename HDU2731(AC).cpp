#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int gcd(int a, int b)
{
	if(a == b){
		return a;
	}else{
		while(true){
			if(a < b){
				if(b % a){
					b = b % a;
				}else{
					return a;
				}
			}else{
				if(a % b){
					a = a % b;
				}else{
					return b;
				}
			}
		}
	}
}

int lcm(int a, int b)
{
	return a * b / gcd(a, b);
}

class Fraction
{
public:
	int n;
	int d;
	
	Fraction(int n, int d): n(n), d(d){};
	bool operator < (const Fraction &f);
	bool operator <= (const Fraction &f);
	bool operator > (const Fraction &f);
	bool operator >= (const Fraction &f);
	bool operator == (const Fraction &f);
	Fraction operator - (const Fraction &f);
};

bool Fraction::operator < (const Fraction &f)
{
	return this->n * f.d < f.n * this->d;
}

bool Fraction::operator <= (const Fraction &f)
{
	return this->n * f.d <= f.n * this->d;
}

bool Fraction::operator > (const Fraction &f)
{
	return this->n * f.d > f.n * this->d;
}

bool Fraction::operator >= (const Fraction &f)
{
	return this->n * f.d >= f.n * this->d;
}

bool Fraction::operator == (const Fraction &f)
{
	return this->n * f.d == f.n * this->d;
}

Fraction Fraction::operator - (const Fraction &f)
{
	int t;
	int d, n;

	d = lcm(this->d, f.d);
	n = this->n * (d / this->d) - f.n * (d / f.d);
	if(n == 0){
		d = 1;
	}else{
		t = gcd(n, d);
		n = n / t;
		d = d / t;
	}

	return Fraction(n, d);
}

int main()
{
	int b, e;
	int i, j, n0, d0;
	Fraction l(0, 1), r(0, 1), f(0, 1);
	int a[300], ac;
	int t, ti;

	while(scanf("%d", &t) == 1){
		for(ti = 1; ti <= t; ++ti){
			scanf("%d%d%d%d", &f.n, &f.d, &b, &e);
			n0 = f.n;
			d0 = f.d;

			f.n %= f.d;
			ac = 0;
			memset(a, 0, 300 * sizeof(int));
			for(i = 0; i <= e; ++i){
				for(j = 0; j < 7; ++j){
					l.n = j;
					l.d = 7;
					r.n = j + 1;
					r.d = 7;
					if(f >= l && f < r){
						f = f - l;
						a[ac++] = j;
						if(f.d % 7){
							f.n *= 7;
						}else{
							f.d /= 7;
						}
						break;
					}
				}
			}

			printf("Problem set %d: %d / %d, base 7 digits %d through %d: ", ti, n0, d0, b, e);
			for(i = b; i <= e; ++i){
				printf("%d", a[i]);
			}
			printf("\n");
		}
	}

	return 0;
}
