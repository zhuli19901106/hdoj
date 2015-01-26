#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
using namespace std;

int na, nb, nc;
int ns;
const int MAXN = 505;
int sum;
int a[MAXN], b[MAXN], c[MAXN];
bool suc;
map<int, int> mm;

int main()
{
	int i, j;
	int si;
	int ti;
	
	ti = 0;
	while(scanf("%d%d%d", &na, &nb, &nc) == 3){
		++ti;
		printf("Case %d:\n", ti);
		for(i = 0; i < na; ++i){
			scanf("%d", &a[i]);
		}
		for(i = 0; i < nb; ++i){
			scanf("%d", &b[i]);
		}
		for(i = 0; i < nc; ++i){
			scanf("%d", &c[i]);
		}

		mm.clear();
		for(i = 0; i < na; ++i){
			for(j = 0; j < nb; ++j){
				mm[a[i] + b[j]] = 0;
			}
		}

		scanf("%d", &ns);
		for(si = 0; si < ns; ++si){
			scanf("%d", &sum);
			suc = false;
			for(i = 0; i < nc; ++i){
				if(mm.find(sum - c[i]) != mm.end()){
					suc = true;
					break;
				}
			}
			if(suc){
				printf("YES\n");
			}else{
				printf("NO\n");
			}
		}
	}

	return 0;
}
