#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;

__int64 a[3];

int main()
{
	int m, n;

	while(scanf("%d%d", &m, &n) == 2 && (m || n)){
		if(m % 2 && n % 2){
			printf("What a pity!\n");
		}else{
			printf("Wonderful!\n");
		}
	}

	return 0;
}
