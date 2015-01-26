#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

__int64 a[64];
int x[80], y[80], z[80], cx, cy, cz;
int n;
int res;
__int64 s;

int move(int x[], int y[], int z[], int &cx, int &cy, int &cz, __int64 s, int n)
{
	int j;

	if(s < a[n - 1]){
		return move(x, z, y, cx, cz, cy, s, n - 1);
	}else if(s == a[n - 1]){
		for(j = cx - 1 - n + 2; j <= cx - 1; ++j){
			y[cy++] = x[j];
		}
		cx -= (n - 1);
		return y[cy - 1];
	}else if(s == a[n - 1] + 1){
		for(j = cx - 1 - n + 2; j <= cx - 1; ++j){
			y[cy++] = x[j];
		}
		cx -= (n - 1);
		z[cz++] = x[cx - 1];
		--cx;
		return z[cz - 1];
	}else if(s < a[n]){
		for(j = cx - 1 - n + 2; j <= cx - 1; ++j){
			y[cy++] = x[j];
		}
		cx -= (n - 1);
		z[cz++] = x[cx - 1];
		--cx;
		return move(y, x, z, cy, cx, cz, s - a[n - 1] - 1, n - 1);
	}else{
		for(j = cx - 1 - n + 1; j <= cx - 1; ++j){
			z[cz++] = x[j];
		}
		cx -= n;

		return z[cz - 1];
	}
}

int main()
{
	int i;

	a[0] = 0;
	for(i = 1; i < 64; ++i){
		a[i] = 2 * a[i - 1] + 1;
	}
	
	while(scanf("%d%I64d", &n, &s) == 2 && (n || s)){
		cy = cz = 0;
		for(i = 0; i < n; ++i){
			x[i] = n - i;
		}
		cx = n;
		res = move(x, y, z, cx, cy, cz, s, n);
		printf("%d\n", res);
	}

	return 0;
}
