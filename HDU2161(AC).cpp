#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int b[16001];

int main()
{
	int i, j;

	memset(b, 0, 16001 * sizeof(int));
	b[0] = 1;
	b[1] = 1;
	for(i = 2; i * i <= 16000; ++i){
		if(b[i]){
			continue;
		}
		for(j = i; j * i <= 16000; ++j){
			b[j * i] = 1;
		}
	}

	for(i = 0; i <= 16000; ++i){
		b[i] = !b[i];
	}
	b[2] = 0;

	j = 0;
	while(scanf("%d", &i) == 1 && i > 0){
		++j;
		if(b[i]){
			printf("%d: yes\n", j);
		}else{
			printf("%d: no\n", j);
		}
	}

	return 0;
}
