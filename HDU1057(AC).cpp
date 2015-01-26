#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int a[2][22][22];
int first, second;
int day;
int d[16];

int main()
{
	int case_count;
	int di, i, j;
	
	scanf("%d", &case_count);
	while(case_count--){
		scanf("%d", &day);
		for(i = 0; i < 16; ++i){
			scanf("%d", &d[i]);
		}
		memset(a, 0, 2 * 22 * 22 * sizeof(int));
		for(i = 1; i <= 20; ++i){
			for(j = 1; j <= 20; ++j){
				scanf("%d", &a[0][i][j]);
			}
		}
		first = 0;
		second = 1;
		for(di = 0; di < day; ++di){
			for(i = 1; i <= 20; ++i){
				for(j = 1; j <= 20; ++j){
					a[second][i][j] = a[first][i][j] + d[a[first][i][j] + a[first][i - 1][j] + a[first][i + 1][j] + a[first][i][j - 1] + a[first][i][j + 1]];
					if(a[second][i][j] > 3){
						a[second][i][j] = 3;
					}
					if(a[second][i][j] < 0){
						a[second][i][j] = 0;
					}
				}
			}
			first = !first;
			second = !second;
		}
		
		for(i = 1; i <= 20; ++i){
			for(j = 1; j <= 20; ++j){
				switch(a[first][i][j]){
					case 0:
						printf(".");
						break;
					case 1:
						printf("!");
						break;
					case 2:
						printf("X");
						break;
					case 3:
						printf("#");
						break;
				}
			}
			printf("\n");
		}

		if(case_count){
			printf("\n");
		}
	}
	
	return 0;
}
