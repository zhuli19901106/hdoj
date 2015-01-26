#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

int n, m, k;
typedef struct st{
	int n;
	double d;
}st;
vector<st> v;

bool comparator(const st &a, const st &b)
{
	if(a.d == b.d){
		return a.n < b.n;
	}else{
		return a.d > b.d;
	}
}

bool comparator2(const st &a, const st &b)
{
	return a.n > b.n;
}

int main()
{
	st vst;
	int i, j;
	double d;

	while(scanf("%d%d%d", &n, &m, &k) == 3){
		v.clear();
		for(i = 0; i < m; ++i){
			vst.n = i + 1;
			vst.d = 0;
			v.push_back(vst);
		}
		for(i = 1; i <= n; ++i){
			for(j = 0; j < m; ++j){
				scanf("%lf", &d);
				v[j].d += d;
			}
		}
		sort(v.begin(), v.end(), comparator);
		sort(&v[0], &v[k], comparator2);
		for(i = 0; i < k; ++i){
			if(i == 0){
				printf("%d", v[i].n);
			}else{
				printf(" %d", v[i].n);
			}
		}
		printf("\n");
	}

	return 0;
}
