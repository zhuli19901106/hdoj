#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAXN = 32010;
int lv[MAXN];
int c[MAXN];
int n;

inline int low_bit(const int &x)
{
	return x & (-x);
}

void add_value(int i, int v)
{
	while(i < MAXN){
		c[i] += v;
		i += low_bit(i);
	}
}

int get_sum(int i)
{
	int sum;

	sum = 0;
	while(i > 0){
		sum += c[i];
		i -= low_bit(i);
	}

	return sum;
}

int main()
{
	int i;
	int x, y;

	while(scanf("%d", &n) == 1){
		memset(lv, 0, MAXN * sizeof(int));
		memset(c, 0, MAXN * sizeof(int));
		for(i = 1; i <= n; ++i){
			scanf("%d%d", &x, &y);
			++x;
			++y;
			add_value(x, 1);
			++lv[get_sum(x)];
		}
		for(i = 1; i <= n; ++i){
			printf("%d\n", lv[i]);
		}
	}

	return 0;
}
