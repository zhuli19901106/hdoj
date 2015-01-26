#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

int main()
{
	int a, b;
	int t;

	while(scanf("%d", &t) == 1){
		while(t--){
			scanf("%d%d", &a, &b);
			printf("%d\n", a + b);
		}
	}

	return 0;
}
