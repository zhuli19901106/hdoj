#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <vector>
using namespace std;

int main()
{
	int a[4];
	int i, j;
	int tmp;
	int ti;
	vector<int> v[10];
	map<int, int> mm;

	ti = 0;
	while(scanf("%d%d%d%d", &a[0], &a[1], &a[2], &a[3]) == 4 && (a[0] || a[1] || a[2] || a[3])){
		++ti;
		if(ti > 1){
			printf("\n");
		}
		mm.clear();
		for(i = 0; i < 10; ++i){
			v[i].clear();
		}
		for(i = 0; i < 24; ++i){
			tmp = a[0] * 1000 + a[1] * 100 + a[2] * 10 + a[3];
			if(mm.find(tmp) == mm.end()){
				mm[tmp] = a[0];
				v[a[0]].push_back(tmp);
			}
			next_permutation(a, a + 4);
		}

		for(i = 0; i < 10; ++i){
			sort(v[i].begin(), v[i].end());
		}
		for(i = 1; i < 10; ++i){
			if(v[i].size() > 0){
				for(j = 0; j < (int)v[i].size(); ++j){
					printf((j ? " %d" : "%d"), v[i][j]);
				}
				printf("\n");
			}
		}
	}
	
	return 0;
}
