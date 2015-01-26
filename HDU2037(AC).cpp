#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

typedef struct st{
	int s;
	int e;
}st;

bool comparator(const st &a, const st &b)
{
	if(a.s == b.s){
		return a.e < b.e;
	}else{
		return a.s < b.s;
	}
}

vector<st> v;
int n;
int dp[200];

int main()
{
	int i, j;
	st vst;

	while(scanf("%d", &n) == 1 && n){
		v.clear();
		for(i = 0; i < n; ++i){
			scanf("%d%d", &vst.s, &vst.e);
			v.push_back(vst);
		}
		sort(v.begin(), v.end(), comparator);
		for(i = 0; i < n; ++i){
			dp[i] = 1;
			for(j = 0; j < i; ++j){
				if(v[j].e <= v[i].s && dp[j] + 1 > dp[i]){
					dp[i] = dp[j] + 1;
				}
			}
		}

		j = dp[0];
		for(i = 1; i < n; ++i){
			if(dp[i] > j){
				j = dp[i];
			}
		}

		printf("%d\n", j);
	}

	return 0;
}
