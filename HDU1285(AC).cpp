#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int MAXN = 505;
int a[MAXN][MAXN];
int in[MAXN];
int b[MAXN];
int n, m;
vector<int> v;

int main()
{
	int x, y;
	int i;
	int cc;

	while (scanf("%d%d", &n, &m) == 2) {
		memset(a, 0, MAXN * MAXN * sizeof(int));
		memset(in, 0, MAXN * sizeof(int));
		for (i = 0; i < m; ++i) {
			scanf("%d%d", &x, &y);
			if (a[x][y] == 0) {
				a[x][y] = 1;
				++in[y];
			}
		}

		v.clear();
		memset(b, 0, MAXN * sizeof(int));
		cc = n;
		while (cc > 0) {
			for (x = 1; x <= n; ++x) {
				if (b[x] == 0 && in[x] == 0) {
					break;
				}
			}
			if (x > n) {
				// there exists a loop in the graph
				break;
			}
			v.push_back(x);
			b[x] = 1;
			--cc;
			for (i = 1; i <= n; ++i) {
				if (a[x][i]) {
					a[x][i] = 0;
					--in[i];
				}
			}
		}

		for (i = 0; i < (int)v.size(); ++i) {
			if (i > 0) {
				printf(" %d", v[i]);
			} else {
				printf("%d", v[i]);
			}
		}
		printf("\n");
	}

	return 0;
}