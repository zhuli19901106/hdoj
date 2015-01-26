#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

const int MAXN = 105;
int f[MAXN][MAXN];
int g[MAXN][MAXN];
int n, m;
int cc;
int dj[MAXN];
typedef struct st{
	int a;
	int b;
	int d;
}st;
int res;

bool comparator(const st &a, const st &b)
{
	if(a.d == b.d){
		if(a.a == b.a){
			return a.b < b.b;
		}else{
			return a.a < b.a;
		}
	}else{
		return a.d < b.d;
	}
}

vector<st> v1, v2;

int find_root(int x)
{
	int k, r;

	r = x;
	while(r != dj[r]){
		r = dj[r];
	}

	k = x;
	while(x != dj[x]){
		x = dj[x];
		dj[k] = r;
		k = x;
	}

	return r;
}

int main()
{
	int i, j;
	int a, b;
	int ra, rb;
	st e;

	while(scanf("%d", &n) == 1){
		memset(f, 0, MAXN * MAXN * sizeof(int));
		memset(g, 0, MAXN * MAXN * sizeof(int));
		for(i = 1; i <= n; ++i){
			for(j = 1; j <= n; ++j){
				scanf("%d", &f[i][j]);
			}
		}

		scanf("%d", &m);
		v1.clear();
		for(i = 1; i <= m; ++i){
			scanf("%d%d", &a, &b);
			g[a][b] = 1;
			g[b][a] = 1;
			e.a = a;
			e.b = b;
			e.d = f[a][b];
			v1.push_back(e);
		}
		sort(v1.begin(), v1.end(), comparator);

		v2.clear();
		for(i = 1; i <= n; ++i){
			for(j = 1; j <= n; ++j){
				if(i != j && !g[i][j] && f[i][j] > 0){
					e.a = i;
					e.b = j;
					e.d = f[i][j];
					v2.push_back(e);
				}
			}
		}
		sort(v2.begin(), v2.end(), comparator);

		for(i = 1; i <= n; ++i){
			dj[i] = i;
		}

		res = 0;
		cc = 0;
		for(i = 0; i < (int)v1.size(); ++i){
			if(cc >= n - 1){
				break;
			}
			ra = find_root(v1[i].a);
			rb = find_root(v1[i].b);
			if(ra != rb){
				dj[ra] = rb;
				find_root(v1[i].a);
				find_root(v1[i].b);
				++cc;
			}
		}

		for(i = 0; i < (int)v2.size(); ++i){
			if(cc >= n - 1){
				break;
			}
			ra = find_root(v2[i].a);
			rb = find_root(v2[i].b);
			if(ra != rb){
				dj[ra] = rb;
				find_root(v2[i].a);
				find_root(v2[i].b);
				res += v2[i].d;
				++cc;
			}
		}

		printf("%d\n", res);
	}

	return 0;
}
