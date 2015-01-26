#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
using namespace std;

const int INF = 1000000000;
const int d[4][2] = {
	{-1, 0}, {+1, 0}, {0, -1}, {0, +1}
};

typedef struct{
	int x;
	int y;
}st;

const int MAXN = 105;
st path[MAXN][MAXN];
int c[MAXN][MAXN];
char mm[MAXN][MAXN];
char s[1000];
queue<st> q;
vector<st> v;
int n, m;

int main()
{
	int i, j;
	st p1, p2;

	while(scanf("%d%d", &n, &m) == 2){
		memset(mm, 'X', MAXN * MAXN * sizeof(char));
		for(i = 0; i <= n + 1; ++i){
			for(j = 0; j <= m + 1; ++j){
				c[i][j] = INF;
			}
		}
		for(i = 1; i <= n; ++i){
			scanf("%s", s);
			for(j = 1; j <= m; ++j){
				mm[i][j] = s[j - 1];
			}
		}
		for(i = 1; i <= n; ++i){
			for(j = 1; j <= m; ++j){
				path[i][j].x = -1;
				path[i][j].y = -1;
			}
		}

		//Start o BFS
		p1.x = 1;
		p1.y = 1;
		c[p1.x][p1.y] = 0;
		q.push(p1);
		while(!q.empty()){
			p1 = q.front();
			q.pop();
			for(i = 0; i < 4; ++i){
				p2.x = p1.x + d[i][0];
				p2.y = p1.y + d[i][1];
				if(mm[p2.x][p2.y] == '.'){
					//This block is clear.
					if(c[p1.x][p1.y] + 1 < c[p2.x][p2.y]){
						c[p2.x][p2.y] = c[p1.x][p1.y] + 1;
						path[p2.x][p2.y].x = p1.x;
						path[p2.x][p2.y].y = p1.y;
						q.push(p2);
					}
				}else if(mm[p2.x][p2.y] >= '1' && mm[p2.x][p2.y] <= '9'){
					//This block is occupied by a monster.
					if(c[p1.x][p1.y] + 1 + (mm[p2.x][p2.y] -  '0') < c[p2.x][p2.y]){
						c[p2.x][p2.y] = c[p1.x][p1.y] + 1 + (mm[p2.x][p2.y] -  '0');
						path[p2.x][p2.y].x = p1.x;
						path[p2.x][p2.y].y = p1.y;
						q.push(p2);
					}
				}
			}
		}

		if(path[n][m].x == -1 || path[n][m].y == -1){
			printf("God please help our poor hero.\n");
		}else{
			v.clear();
			p1.x = n;
			p1.y = m;
			while(!(p1.x == 1 && p1.y == 1)){
				v.push_back(p1);
				p2 = p1;
				p1.x = path[p2.x][p2.y].x;
				p1.y = path[p2.x][p2.y].y;
			}
			v.push_back(p1);

			int cc;

			if(mm[n][m] == '.'){
				printf("It takes %d seconds to reach the target position, let me show you the way.\n", c[n][m]);
			}else if(mm[n][m] >= '1' && mm[n][m] <= '9'){
				printf("It takes %d seconds to reach the target position, let me show you the way.\n", c[n][m]);
			}
			/*
			for(i = 1; i <= n; ++i){
				for(j = 1; j <= m; ++j){
					if(c[i][j] != INF){
						printf("%2d ", c[i][j]);
					}else{
						printf(" X ");
					}
				}
				printf("\n");
			}
			*/
			cc = 1;
			for(i = (int)v.size() - 1; i >= 1; --i){
				if(mm[v[i].x][v[i].y] == '.'){
					printf("%ds:(%d,%d)->(%d,%d)\n", cc, v[i].x - 1, v[i].y - 1, v[i - 1].x - 1, v[i - 1].y - 1);
					++cc;
				}else if(mm[v[i].x][v[i].y] >= '1' && mm[v[i].x][v[i].y] <= '9'){
					for(j = 1; j <= mm[v[i].x][v[i].y] - '0'; ++j){
						printf("%ds:FIGHT AT (%d,%d)\n", cc, v[i].x - 1, v[i].y - 1);
						++cc;
					}
					printf("%ds:(%d,%d)->(%d,%d)\n", cc, v[i].x - 1, v[i].y - 1, v[i - 1].x - 1, v[i - 1].y - 1);
					++cc;
				}
			}
			if(mm[n][m] >= '1' && mm[n][m] <= '9'){
				for(i = 1; i <= (mm[n][m] - '0'); ++i){
					printf("%ds:FIGHT AT (%d,%d)\n", cc, n - 1, m - 1);
					++cc;
				}
			}
		}
		printf("FINISH\n");
		while(!q.empty()){
			q.pop();
		}
	}

	return 0;
}
