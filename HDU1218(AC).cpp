#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int a[2][20][20];
int r, c;
int first, second;

int main()
{
	char str[1000];
	int i, j;
	
	while(true){
		if(scanf("%s", &str) != 1){
			break;
		}else if(strcmp(str, "ENDOFINPUT") == 0){
			break;
		}
		
		scanf("%d%d", &r, &c);
		first = 0;
		second = !first;
		for(i = 0; i < r; ++i){
			scanf("%s", str);
			for(j = 0; j < c; ++j){
				a[first][i][j] = str[j] - '0';
			}
		}
		scanf("%s", str);
		for(i = 0; i < r - 1; ++i){
			for(j = 0; j < c - 1; ++j){
				a[second][i][j] = (a[first][i][j] + a[first][i][j + 1] + a[first][i + 1][j] + a[first][i + 1][j + 1]) / 4;
			}
		}
		for(i = 0; i < r - 1; ++i){
			for(j = 0; j < c - 1; ++j){
				printf("%d", a[second][i][j]);
			}
			printf("\n");
		}
	}
	
	return 0;
}
