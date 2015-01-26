#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

int main()
{
	char s[100];
	int i, sum;
	int ti;

	ti = 0;
	while(scanf("%s", s) == 1){
		++ti;
		if(ti > 1){
			printf("\n");
		}
		sum = 0;
		for(i = 0; s[i]; ++i){
			if(s[i] >= '0' && s[i] <= '9' && (s[i] - '0') % 2 == 0){
				sum += (s[i] - '0');
			}
		}
		printf("%d\n", sum);
	}

	return 0;
}
