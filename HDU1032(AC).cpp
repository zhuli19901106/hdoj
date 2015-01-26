#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;

int getlength(int n)
{
	int count;

	count = 1;
	while(n != 1){
		if(n % 2 == 1){
			n = 3 * n + 1;
		}else{
			n = n / 2;
		}
		count++;
	}

	return count;
}

int main()
{
	int i, len;
	int x;
	int y;
	int x0, y0;
	int maxi, maxlen;
	
	while(true){
		if(scanf("%d%d", &x, &y) != 2){
			break;
		}
		x0 = x;
		y0 = y;
		if(x > y){
			x ^= y ^= x ^= y;
		}

		maxi = x;
		maxlen = getlength(maxi);
		for(i = x + 1; i <= y; ++i){
			len = getlength(i);
			if(len > maxlen){
				maxi = i;
				maxlen = len;
			}
		}

		printf("%d %d %d\n", x0, y0, maxlen);
	}

	return 0;
}
