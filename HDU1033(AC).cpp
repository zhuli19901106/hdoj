#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

const int N = 0;
const int S = 1;
const int W = 2;
const int E = 3;
const int a[4] = {E, W, N, S};
const int v[4] = {W, E, S, N};
int d[4][2] = {{0, 10}, {0, -10}, {-10, 0}, {10, 0}};
int dir;
int x, y;

int main()
{
	char s[1000];
	int i;

	while(scanf("%s", s) == 1){
		printf("300 420 moveto\n");
		printf("310 420 lineto\n");

		x = 310;
		y = 420;
		dir = E;
		for(i = 0; s[i]; ++i){
			if(s[i] == 'V'){
				dir = v[dir];
				x = x + d[dir][0];
				y = y + d[dir][1];
				printf("%d %d lineto\n", x, y);
			}else if(s[i] == 'A'){
				dir = a[dir];
				x = x + d[dir][0];
				y = y + d[dir][1];
				printf("%d %d lineto\n", x, y);
			}
		}

		printf("stroke\nshowpage\n");
	}

	return 0;
}
