#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main()
{
	int sum;
	int n;
	int i;
	int tmp;

	while(scanf("%d", &n) == 1 && n){
		sum = 0;
		for(i = 0; i < n; ++i){
			scanf("%d", &tmp);
			sum += tmp * tmp;
		}
		printf("%d\n", sum);
	}

	return 0;
}
