#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
	int n;
	int a[100];
	int ac;

	while(scanf("%d", &n) == 1){
		if(n == 0){
			printf("0\n");
		}else{
			ac = 0;
			while(n){
				a[ac++] = n & 1;
				n >>= 1;
			}
			for(int i = ac - 1; i >= 0; --i){
				printf("%d", a[i]);
			}
			printf("\n");
		}
	}

	return 0;
}
