#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
	long long int n;
	
	while(scanf("%lld", &n) == 1){
		while(n > 18){
			n = (n + 17) / 18;
		}
		if(n <= 9){
			printf("Stan wins.\n");
		}else{
			printf("Ollie wins.\n");
		}
	}

	return 0;
}
