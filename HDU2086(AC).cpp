#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>

using namespace std;

const int MAXN = 3005;
double a0, a1, an1;
double k[MAXN];
double b[MAXN];
double c[MAXN];
int n;

int main()
{
	int i;

	while(scanf("%d", &n) == 1){
		scanf("%lf", &a0);
		scanf("%lf", &an1);
		for(i = 1; i <= n; ++i){
			scanf("%lf", &c[i]);
		}

		k[0] = 0.0;
		b[0] = a0;
		k[1] = 1.0;
		b[1] = 0.0;
		for(i = 2; i <= n + 1; ++i){
			k[i] = 2 * k[i - 1] - k[i - 2];
			b[i] = 2 * b[i - 1] - b[i - 2] + 2 * c[i - 1];
		}
		a1 = (an1 - b[n + 1]) / k[n + 1];

		printf("%.2f\n", a1);
	}

	return 0;
}
