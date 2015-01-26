#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	int n;
	int i;
	int j;
	int k;
	int len;
	char buffer[1000];

	while(true){
		if(scanf("%d", &n) != 1){
			break;
		}

		for(i = 1; i <= n; i++){
			scanf("%d", &k);
			scanf("%s", buffer);
			len = strlen(buffer);

			printf("%d ", i);
			for(j = 0; j < len; j++){
				if(j == k - 1){
					continue;
				}else{
					printf("%c", buffer[j]);
				}
			}
			printf("\n");
		}
	}

	return 0;
}
