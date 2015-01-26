#define _CRT_SECURE_NO_WARNINGS
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
	int n;

	while(scanf("%d", &n) == 1){
		printf("%.0f\n", 1.0 + (n - 2) * pow(2.0, n - 1));
	}

	return 0;
}
