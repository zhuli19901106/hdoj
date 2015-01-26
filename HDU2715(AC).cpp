#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
	int n;
	int result;
	int i;

	while(true){
		if(scanf("%d", &n) != 1){
			break;
		}
		result = 0;
		for(i = 1; i <= sqrt(2 * n + 1.0); ++i){
			if(
				2 * n % i == 0
				&&
				2 * n / i + 1 - i > 0
				&&
				(2 * n / i + 1 - i) % 2 == 0
			){
				++result;
			}
		}
		printf("%d\n", result);
	}

	return 0;
}
