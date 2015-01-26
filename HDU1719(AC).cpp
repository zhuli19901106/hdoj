#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main()
{
	int n;

	while(scanf("%d", &n) == 1){
		if(!n){
			printf("NO!\n");
			continue;
		}
		++n;
		while(n % 2 == 0){
			n /= 2;
		}
		while(n % 3 == 0){
			n /= 3;
		}
		if(n == 1){
			printf("YES!\n");
		}else{
			printf("NO!\n");
		}
	}

	return 0;
}
