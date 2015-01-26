#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int y, m, d;
int md[13] = {
	0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};
int res;

int isleap(int y)
{
	return y % 100 == 0 ? y % 400 == 0 : y % 4 == 0;
}

int main()
{
	int i;

	while(scanf("%4d%*1s%2d%*1s%2d", &y, &m, &d) == 3){
		if(isleap(y)){
			md[2] = 29;
		}else{
			md[2] = 28;
		}
		res = 0;
		for(i = 1; i < m; ++i){
			res += md[i];
		}
		res += d;
		printf("%d\n", res);
	}

	return 0;
}
