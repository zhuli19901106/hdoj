#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

int main()
{
	int a, b;

	while(scanf("%d%d", &a, &b) == 2){
		if((a + b) % 86 == 0){
			printf("yes\n");
		}else{
			printf("no\n");
		}
	}

	return 0;
}
