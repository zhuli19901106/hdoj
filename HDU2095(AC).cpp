#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
	int res, tmp;
	int n;
	
	while(scanf("%d", &n) == 1 && n){
		res = 0;
		while(n--){
			scanf("%d", &tmp);
			res ^= tmp;
		}
		printf("%d\n", res);
	}

	return 0;
}
