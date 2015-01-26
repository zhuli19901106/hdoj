#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
#include <string>
using namespace std;

int a, b, k, pw;

int main()
{
	int i;

	while(scanf("%d%d%d", &a, &b, &k) == 3 && (a || b)){
		pw = 1;
		for(i = 0; i < k; ++i){
			pw *= 10;
		}
		if(a % pw == b % pw){
			printf("-1\n");
		}else{
			printf("%d\n", a + b);
		}
	}

	return 0;
}
