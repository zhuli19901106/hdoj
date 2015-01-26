#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
	int i;
	int j;
	int n;
	int ti;
	int t;
	int a[10000][5];
	int mask;

	scanf("%d", &t);
	for(ti = 1; ti <= t; ti++){
		if(scanf("%d", &n) != 1){
			break;
		}

		for(i = 0; i < n; i++){
			for(j = 0; j < 5; j++){
				scanf("%2X", &a[i][j]);
			}
		}

		printf("Case %d:\n\n", ti);
		mask = 0x01;
		while(mask != 0x80){
			for(i = 0; i < n; i++){
				for(j = 0; j < 5; j++){
					if((a[i][j] & mask) != 0){
						printf("#");
					}else{
						printf(" ");
					}
				}
				if(i < n - 1){
					printf(" ");
				}else{
					printf("\n");
				}
			}

			mask = mask << 1;
		}
		printf("\n");
	}

	return 0;
}
