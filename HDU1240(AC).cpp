#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
using namespace std;

int n;
int f[12][12][12];
int v[12][12][12];
char mat[12][12][12];
int d[6][3] = {
	{ 0,  0, -1},
	{ 0,  0, +1},
	{ 0, -1,  0},
	{ 0, +1,  0},
	{-1,  0,  0},
	{+1,  0,  0}
};
//mat[z][y][x]
typedef struct point{
	int x, y, z;
	int d;
}Point;

int main()
{
	char s[1000];
	int i, j, k;
	Point src, dst;
	Point pin, pout;
	queue<Point> q;
	
	while(true){
		if(scanf("%s%d", s, &n) != 2){
			break;
		}
		for(i = 0; i <= n + 1; ++i){
			for(j = 0; j <= n + 1; ++j){
				for(k = 0; k <= n + 1; ++k){
					mat[i][j][k] = 'X';
				}
			}
		}
		
		for(i = 1; i <= n; ++i){
			for(j = 1; j <= n; ++j){
				scanf("%s", s);
				for(k = 1; k <= n; ++k){
					mat[i][j][k] = s[k - 1];
				}
			}
		}
		
		scanf("%d%d%d", &src.x, &src.y, &src.z);
		++src.x;
		++src.y;
		++src.z;
		scanf("%d%d%d", &dst.x, &dst.y, &dst.z);
		++dst.x;
		++dst.y;
		++dst.z;
		scanf("%s", s);

		memset(f, 0, 12 * 12 * 12 * sizeof(int));
		memset(v, 0, 12 * 12 * 12 * sizeof(int));
		v[src.z][src.y][src.x] = 1;
		src.d = 0;
		q.push(src);
		while(!q.empty()){
			pout = q.front();
			q.pop();
			if(pout.x == dst.x && pout.y == dst.y && pout.z == dst.z){
				break;
			}

			for(i = 0; i < 6; ++i){
				pin = pout;
				pin.x += d[i][0];
				pin.y += d[i][1];
				pin.z += d[i][2];
				++pin.d;
				if( !v[pin.z][pin.y][pin.x] && mat[pin.z][pin.y][pin.x] == 'O')
				{
					v[pin.z][pin.y][pin.x] = 1;
					q.push(pin);
				}
			}
		}
		while(!q.empty()){
			q.pop();
		}

		if(pout.x == dst.x && pout.y == dst.y && pout.z == dst.z){
			printf("%d %d\n", n, pout.d);
		}else{
			printf("NO ROUTE\n");
		}
	}

	return 0;
}
