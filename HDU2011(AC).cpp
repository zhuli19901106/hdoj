#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

double sum;
int m, flag;

int main()
{
	int n, ni;
	int i;

	while(scanf("%d", &n) == 1){
		for(ni = 0; ni < n; ++ni){
			scanf("%d", &m);
			sum = 0;
			flag = 1;
			for(i = 1; i <= m; ++i){
				sum += (flag * 1.0 / i);
				flag = -flag;
			}
			printf("%.2f\n", sum);
		}
	}

	return 0;
}
