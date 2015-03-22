#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int N = 505;
const int W = 10005;
int e, f;
int n;
int p[N];
int w[N];
int a[W];

int main()
{
	int t, ti;
	int i, j;
	int p1, w1;

	scanf("%d", &t);
	for (ti = 0; ti < t; ++ti) {
		scanf("%d%d", &e, &f);
		scanf("%d", &n);
		j = 1;
		for (i = 0; i < n; ++i) {
			scanf("%d%d", &p1, &w1);
			if (w1 == 0 || w1 > f - e) {
				continue;
			}
			p[j] = p1;
			w[j] = w1;
			++j;
		}
		n = j - 1;
		f -= e;
		memset(a, -1, sizeof(a));
		a[0] = 0;
		for (i = 1; i <= n; ++i) {
			for (j = 0; j + w[i] <= f; ++j) {
				if (a[j] == -1) {
					continue;
				}
				if (a[j + w[i]] == -1) {
					a[j + w[i]] = a[j] + p[i];
					continue;
				}
				a[j + w[i]] = min(a[j + w[i]], a[j] + p[i]);
			}
		}
		if (a[f] == -1) {
			printf("This is impossible.\n");
		} else {
			printf("The minimum amount of money in the piggy-bank is %d.\n", a[f]);
		}
	}

	return 0;
}