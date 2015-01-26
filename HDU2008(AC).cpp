#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int a, b, c;
int n;

int main()
{
	int i;
	double tmp;

	while(scanf("%d", &n) == 1 && n){
		a = b = c = 0;
		for(i = 0; i < n; ++i){
			scanf("%lf", &tmp);
			if(tmp > 0){
				++c;
			}else if(tmp < 0){
				++a;
			}else{
				++b;
			}
		}

		printf("%d %d %d\n", a, b, c);
	}

	return 0;
}
