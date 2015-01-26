#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

double sum, term;
int n, m;

int main()
{
	int i;

	while(scanf("%d%d", &n, &m) == 2){
		sum = 0;
		term = n;
		for(i = 0; i < m; ++i){
			sum += term;
			term = sqrt(term);
		}
		printf("%.2f\n", sum);
	}

	return 0;
}
