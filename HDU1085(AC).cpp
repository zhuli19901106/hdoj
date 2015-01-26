#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int a, b, c;
int res;

int main()
{
	while(scanf("%d%d%d", &a, &b, &c) == 3 && (a || b || c)){
		if(a == 0){
			printf("%d\n", 1);
		}else{
			if(a + 2 * b < 4){
				printf("%d\n", a + 2 * b + 1);
			}else{
				printf("%d\n", a + 2 * b + c * 5 + 1);
			}
		}
	}

	return 0;
}
