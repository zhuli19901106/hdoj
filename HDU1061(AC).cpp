#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int mypow10(int a, int b)
{
	int tmp;

	if(b == 1){
		return a % 10;
	}else if(b % 2){
		tmp = mypow10(a, b / 2);
		return tmp * tmp * (a % 10) % 10;
	}else{
		tmp = mypow10(a, b / 2);
		return tmp * tmp % 10;
	}
}

int main()
{
	int n;
	int t, ti;

	while(scanf("%d", &t) == 1){
		for(ti = 0; ti < t; ++ti){
			scanf("%d", &n);
			printf("%d\n", mypow10(n, n));
		}
	}

	return 0;
}
