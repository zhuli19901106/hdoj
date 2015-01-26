#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

int n;
int res;

int main()
{
	int i, tmp;

	while(scanf("%d", &n) == 1){
		res = 1;
		for(i = 0; i < n; ++i){
			scanf("%d", &tmp);
			if(tmp % 2){
				res = res * tmp;
			}
		}

		printf("%d\n", res);
	}

	return 0;
}
