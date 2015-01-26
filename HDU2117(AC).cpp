#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int n, m, res;

int main()
{
	int i;

	while(scanf("%d%d", &n, &m) == 2){
		res = 1;
		for(i = 0; i < m - 1; ++i){
			res = res * 10 % n;
		}
		res = res * 10 / n % 10;
		printf("%d\n", res);
	}

	return 0;
}
