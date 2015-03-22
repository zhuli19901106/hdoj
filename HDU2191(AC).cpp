#include <cstdio>
#include <vector>
using namespace std;

vector<int> w;
vector<int> v;
vector<int> dp;
int n, m;
int cc;
int ans;

int main()
{
	int t, ti;
	int v1, w1, c1;
	int i, j, k;

	scanf("%d", &t);
	for (ti = 0; ti < t; ++ti) {
		scanf("%d%d", &n, &m);
		
		for (i = 0; i < m; ++i) {
			scanf("%d%d%d", &w1, &v1, &c1);

			k = 1;
			while (c1 - k > 0) {
				c1 -= k;
				w.push_back(k * w1);
				v.push_back(k * v1);
				k <<= 1;
			}
			w.push_back(c1 * w1);
			v.push_back(c1 * v1);
		}
		
		dp.resize(n + 1, 0);
		
		for(i = 0; i < v.size(); ++i) {
			for(j = n; j >= w[i]; --j) {
				dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
			}
		}
		
		ans = 0;
		for (i = 0; i <= n; ++i) {
			ans = max(ans, dp[i]);
		}
		printf("%d\n", ans);

		dp.clear();
		v.clear();
		w.clear();
	}

	return 0;
}