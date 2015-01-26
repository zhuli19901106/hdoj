#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;

__int64 a[3];

int main()
{
	while(scanf("%I64d%I64d%I64d", &a[0], &a[1], &a[2]) == 3){
		sort(a, a + 3);
		if(a[0] + a[1] == a[2]){
			printf("oh,lucky!\n");
			continue;
		}

		if(a[2] - a[1] == a[0]){
			printf("oh,lucky!\n");
			continue;
		}

		if(a[0] * a[1] == a[2] || a[1] * a[2] == a[0] || a[2] * a[0] == a[1]){
			printf("oh,lucky!\n");
			continue;
		}

		if(a[0] != 0 && ((a[1] % a[0] == 0 && a[1] / a[0] == a[2]) || (a[2] % a[0] == 0 && a[2] / a[0] == a[1]))){
			printf("oh,lucky!\n");
			continue;
		}

		if(a[1] != 0 && ((a[2] % a[1] == 0 && a[2] / a[1] == a[0]) || (a[0] % a[1] == 0 && a[0] / a[1] == a[2]))){
			printf("oh,lucky!\n");
			continue;
		}

		if(a[2] != 0 && ((a[0] % a[2] == 0 && a[0] / a[2] == a[1]) || (a[1] % a[2] == 0 && a[1] / a[2] == a[0]))){
			printf("oh,lucky!\n");
			continue;
		}

		if(a[0] != 0 && (a[1] % a[0] == a[2] || a[2] % a[0] == a[1])){
			printf("oh,lucky!\n");
			continue;
		}

		if(a[1] != 0 && (a[2] % a[1] == a[0] || a[0] % a[1] == a[2])){
			printf("oh,lucky!\n");
			continue;
		}
		if(a[2] != 0 && (a[0] % a[2] == a[1] || a[1] % a[2] == a[0])){
			printf("oh,lucky!\n");
			continue;
		}

		printf("what a pity!\n");
	}

	return 0;
}
