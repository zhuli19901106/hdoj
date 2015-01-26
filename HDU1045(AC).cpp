#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

char map[6][6];
char str[1000];
int n;
int max_bn;
int bn;
int d[4][2] = {
	{ 0, +1},
	{ 0, -1},
	{-1,  0},
	{+1,  0}
};

void dfs(int x, int y, int bn)
{
	int i, j, k;
	int x1, y1;
	
	if(max_bn < bn){
		max_bn = bn;
	}
	
	for(i = 1; i <= n; ++i){
		for(j = 1; j <= n; ++j){
			if(map[i][j] == '.'){
				for(k = 0; k < 4; ++k){
					x1 = i + d[k][0];
					y1 = j + d[k][1];
					while(true){
						if(x1 < 1 || x1 > n || y1 < 1 || y1 > n){
							break;
						}else if(map[x1][y1] == 'X'){
							break;
						}else if(map[x1][y1] == 'B'){
							x1 = -1;
							y1 = -1;
							break;
						}else{
							x1 += d[k][0];
							y1 += d[k][1];
						}
					}
					if(x1 == -1 && y1 == -1){
						break;
					}
				}
				if(k == 4){
					map[i][j] = 'B';
					dfs(i, j, bn + 1);
					map[i][j] = '.';
				}
			}
		}
	}
}

int main()
{
	int i, j;
	
	while(true){
		if(gets(str) == NULL){
 			break;
		}else if(sscanf(str, "%d", &n), n == 0){
			break;
		}
		
		for(i = 0; i <= n + 1; ++i){
			for(j = 0; j <= n + 1; ++j){
				map[i][j] = 'X';
			}
		}
		
		for(i = 1; i <= n; ++i){
			gets(str);
			for(j = 1; j <= n; ++j){
				map[i][j] = str[j - 1];
			}
		}

		max_bn = 0;
		for(i = 1; i <= n; ++i){
			for(j = 1; j <= n; ++j){
				if(map[i][j] == '.'){
					map[i][j] = 'B';
					dfs(i, j, 1);
					map[i][j] = '.';
				}
			}
		}
		
		printf("%d\n", max_bn);
	}
	
	return 0;
}
