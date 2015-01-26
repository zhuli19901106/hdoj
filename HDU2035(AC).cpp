#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
	int a, b;
	int res;
	int i;

	while(scanf("%d%d", &a, &b) == 2 && (a || b)){
		res = 1;
		for(i = 1; i <= b; ++i){
			res = res * a % 1000;
		}
		printf("%d\n", res);
	}

	return 0;
}
