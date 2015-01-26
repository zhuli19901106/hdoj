#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int n1, n2;
int x1, y1, x2, y2;

void myswap(int &x, int &y)
{
	int t;

	t = x;
	x = y;
	y  =t;
}

void getcord(const int n, int &x, int &y)
{
	int i;

	for(i = 1; i * i < n; ++i)
		;
	x = i;
	y = n - (i - 1) * (i - 1);
}

int myabs(const int &a)
{
	return (a > 0) ? a : -a;
}

int mindist(int x1, int y1, int x2, int y2)
{
	int left, right;

	if(y1 % 2 == 0){
		return mindist(x1 - 1, y1 - 1, x2, y2) + 1;
	}else{
		if(y2 % 2 == 0){
			return mindist(x1, y1, x2 - 1, y2 - 1) - 1;
		}else{
			left = y1 - 2 * (x1 - x2);
			right = y1;
			if(y2 >= left && y2 <= right){
				return 2 * (x1 - x2);
			}else if(y2 < left){
				return 2 * (x1 - x2) + (left - y2);
			}else{
				return 2 * (x1 - x2) + (y2 - right);
			}
		}
	}
}

int main()
{
	while(scanf("%d%d", &n1, &n2) == 2){
		getcord(n1, x1, y1);
		getcord(n2, x2, y2);
		if(x1 == x2){
			printf("%d\n", myabs(y1 - y2));
			continue;
		}
		if(x1 < x2){
			myswap(n1, n2);
			myswap(x1, x2);
			myswap(y1, y2);
		}
		printf("%d\n", mindist(x1, y1, x2, y2));
	}

	return 0;
}
