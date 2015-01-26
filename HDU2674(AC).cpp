#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
	int a[41];
	int i;

	a[0] = 1;
	for(i = 1; i <= 40; ++i){
		a[i] = a[i - 1] * i % 2009;
	}

	while(scanf("%d", &i) == 1){
		if(i >= 41){
			printf("0\n");
		}else{
			printf("%d\n", a[i]);
		}
	}

	return 0;
}
