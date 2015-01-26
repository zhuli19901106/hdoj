#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int n;
int sx, sy;
int px, py;
int dx, dy;

int myabs(const int &a)
{
	return (a >= 0 ? a : -a);
}

int mygcd(int a, int b)
{
	while(true){
		if(a >= b){
			if(a % b){
				a = a % b;
			}else{
				return b;
			}
		}else{
			if(b % a){
				b = b % a;
			}else{
				return a;
			}
		}
	}
}

int main()
{
	while(scanf("%d", &n) == 1 && n){
		scanf("%d%d%d%d", &sx, &sy, &px, &py);
		if(myabs(px) > n || myabs(py) > n){
			printf("Out Of Range\n");
			continue;
		}

		dx = myabs(sx - px);
		dy = myabs(sy - py);
		if(dx == 0){
			if(dy == 0){
				printf("Yes\n");
			}else if(dy == 1){
				printf("Yes\n");
			}else{
				printf("No\n");
			}
		}else if(dx == 1){
			printf("Yes\n");
		}else{
			if(dy == 0){
				printf("No\n");
			}else if(mygcd(dx, dy) == 1){
				printf("Yes\n");
			}else{
				printf("No\n");
			}
		}
	}

	return 0;
}
