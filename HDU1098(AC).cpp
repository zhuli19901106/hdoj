#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;
/*
int calc(int n)
{
	int res, sum;
	int i;

	res = 0;

	sum = 1;
	for(i = 0; i < 13; ++i){
		sum = sum * n % 65;
	}
	res += 5 * sum;
	res %= 65;

	sum = 1;
	for(i = 0; i < 5; ++i){
		sum = sum * n % 65;
	}
	res += 13 * sum;
	res %= 65;

	return res;
}

int f[65];
*/
int main()
{
	int i;

	/*
	for(i = 0; i < 65; ++i){
		f[i] = calc(i);
	}
	//common difference is 18
	*/

	int k, a;

	while(scanf("%d", &k) == 1){
		for(a = 0; a < 65; ++a){
			if((a * k + 18) % 65 == 0){
				printf("%d\n", a);
				break;
			}
		}
		if(a >= 65){
			printf("no\n");
		}
	}

	return 0;
}
