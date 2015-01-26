#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

int main()
{
	int res;
	int m, k;

	while(scanf("%d%d", &m, &k) == 2 && (m || k)){
		res = 0;
		while(m >= k){
			res += (m / k * k);
			m = (m % k) + (m / k);
		}
		res += m;

		printf("%d\n", res);
	}

	return 0;
}
