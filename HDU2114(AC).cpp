#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

int main()
{
	int n;

	while(scanf("%d", &n) == 1){
		n = ((n % 10000) * ((n + 1) % 10000) / 2) % 10000;
		printf("%04d\n", n * n % 10000);
	}

	return 0;
}
