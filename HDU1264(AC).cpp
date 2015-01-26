#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAXN = 105;
int a[MAXN][MAXN];

void myswap(int &x, int &y)
{
	int t;

	t = x;
	x = y;
	y = t;
}

int main()
{
	int x1, y1, x2, y2;
	bool eof;
	int i, j;
	int res;

	eof = false;
	while(!eof){
		memset(a, 0, MAXN * MAXN * sizeof(int));
		res = 0;
		while(scanf("%d%d%d%d", &x1, &y1, &x2, &y2)){
			if(x1 == -1 && y1 == -1 && x2 == -1 && y2 == -1){
				break;
			}else if(x1 == -2 && y1 == -2 && x2 == -2 && y2 == -2){
				eof = true;
				break;
			}else{
				if(x1 > x2){
					myswap(x1, x2);
				}
				if(y1 > y2){
					myswap(y1, y2);
				}
				for(i = x1; i < x2; ++i){
					for(j = y1; j < y2; ++j){
						if(!a[i][j]){
							a[i][j] = 1;
							++res;
						}
					}
				}
			}
		}
		if(eof){
			printf("%d\n", res);
			break;
		}else{
			printf("%d\n", res);
		}
	}

	return 0;
}
