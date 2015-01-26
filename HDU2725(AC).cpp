#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

typedef struct st{
	int c;
	int l;
	int i;
	int d;
}st;
vector<st> v;

bool comparator(const st &a, const st &b)
{
	if(a.c == b.c){
		if(a.l == b.l){
			if(a.i == b.i){
				return a.d > b.d;
			}else{
				return a.i > b.i;
			}
		}else{
			return a.l > b.l;
		}
	}else{
		return a.c > b.c;
	}
}

int main()
{
	st t;
	char s[1000];
	int len;
	int p;

	while(scanf("%s", s) == 1 && strcmp(s, "END")){
		len = strlen(s);
		v.clear();
		for(t.i = 0; t.i <= len - 1; ++t.i){
			for(t.d = 1; t.i + t.d <= len; ++t.d){
				p = t.i;
				t.c = 0;
				while(p <= len - 1 && s[p] == '.'){
					++t.c;
					p += t.d;
				}
				if(p <= len - 1){
					t.l = p;
				}else{
					t.l = p - t.d;
				}
				v.push_back(t);
			}
		}
		sort(v.begin(), v.end(), comparator);
		printf("%d %d\n", v[0].i, v[0].d);
	}

	return 0;
}
