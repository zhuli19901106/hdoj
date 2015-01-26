#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
using namespace std;

int a[10000];
int b[10000];
int x, y;
int res;
queue<int> q;

int main()
{
	int i, j;
	int t, ti, x1, x2;
	int d[4];

	b[0] = 1;
	b[1] = 1;
	for(i = 2; i * i < 10000; ++i){
		if(b[i]){
			continue;
		}
		for(j = i; i * j < 10000; ++j){
			b[i * j] = 1;
		}
	}

	for(i = 0; i < 10000; ++i){
		b[i] = !b[i];
	}

	while(scanf("%d", &t) == 1){
		for(ti = 0; ti < t; ++ti){
			scanf("%d%d", &x, &y);
			memset(a, 0, 10000 * sizeof(int));
			a[x] = 1;
			q.push(x);
			while(!q.empty()){
				if(a[y]){
					break;
				}
				x1 = q.front();
				q.pop();
				d[0] = x1 / 1000;
				d[1] = x1 % 1000 / 100;
				d[2] = x1 % 100 / 10;
				d[3] = x1 % 10;
				for(i = 0; !a[y] && i <= 3; ++i){
					for(j = 0; !a[y] && j <= 9; ++j){
						if(i == 0 && j == 0){
							continue;
						}
						if(j == d[i]){
							continue;
						}else{
							if(i == 0){
								x2 = j * 1000 + d[1] * 100 + d[2] * 10 + d[3];
							}else if(i == 1){
								x2 = d[0] * 1000 + j * 100 + d[2] * 10 + d[3];
							}else if(i == 2){
								x2 = d[0] * 1000 + d[1] * 100 + j * 10 + d[3];
							}else{
								x2 = d[0] * 1000 + d[1] * 100 + d[2] * 10 + j;
							}
							if(!a[x2] && b[x2]){
								a[x2] = a[x1] + 1;
								q.push(x2);
							}
						}
					}
				}

				if(a[y]){
					break;
				}
			}

			while(!q.empty()){
				q.pop();
			}

			printf("%d\n", a[y] - a[x]);
		}
	}

	return 0;
}
