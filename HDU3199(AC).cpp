#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

__int64 a[200000];

__int64 mymin(__int64 a, __int64 b, __int64 c)
{
	__int64 m;

	if(a < b){
		m = a;
	}else{
		m = b;
	}

	if(m > c){
		m = c;
	}

	return m;
}

int main()
{
	int n;
	int e1, e2, e3;
	__int64 a1, a2, a3;
	int p1, p2, p3;
	int i;
	
	while(scanf("%d%d%d%d", &p1, &p2, &p3, &n) != EOF){
		a[0] = 1;
		e1 = e2 = e3 = 0;
		for(i = 1; i <= n; ++i){
			a1 = a[e1] * p1;
			a2 = a[e2] * p2;
			a3 = a[e3] * p3;

			a[i] = mymin(a1, a2, a3);
			if(a[i] == a1){
				++e1;
			}
			if(a[i] == a2){
				++e2;
			}
			if(a[i] == a3){
				++e3;
			}
		}
		printf("%I64d\n", a[n]);
	}
	
	return 0;
}
