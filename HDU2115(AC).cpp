#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

typedef struct st{
	string s;
	int t;
}st;
vector<st> v;
int n;

bool comparator(const st &a, const st &b)
{
	if(a.t == b.t){
		return a.s < b.s;
	}else{
		return a.t < b.t;
	}
}

int main()
{
	char s[1000];
	int i, j;
	int ti;
	int x, y;
	st vst;

	ti = 0;
	while(scanf("%d", &n) == 1 && n){
		++ti;
		for(i = 0; i < n; ++i){
			scanf("%s%02d%*1s%02d", s, &x, &y);
			vst.s = string(s);
			vst.t = x * 60 + y;
			v.push_back(vst);
		}
		sort(v.begin(), v.end(), comparator);
		i = 0;
		if(ti > 1){
			printf("\n");
		}
		printf("Case #%d\n", ti);
		while(true){
			if(i >= (int)v.size()){
				break;
			}
			j = i;
			while(j < (int)v.size() && v[j].t == v[i].t){
				printf("%s %d\n", v[j].s.data(), i + 1);
				++j;
			}
			i = j;
		}
		v.clear();
	}

	return 0;
}
