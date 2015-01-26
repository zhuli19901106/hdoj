#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

struct st
{
	int l;
	int w;
};

bool comp(const st &sa, const st &sb)
{
	if(sa.l == sb.l){
		return sa.w < sb.w;
	}else{
		return sa.l < sb.l;
	}
}

int main()
{
	int case_no, case_count;
	int count, count0, n, res;
	int i, j;
	int visited[10000];
	vector<st> a;
	st tmp;
	
	while(true){
		if(scanf("%d", &case_count) != 1){
			break;
		}
		for(case_no = 0; case_no < case_count; ++case_no){
			a.clear();
			scanf("%d", &n);
			for(i = 0; i < n; ++i){
				scanf("%d%d", &tmp.l, &tmp.w);
				a.push_back(tmp);
			}
			sort(a.begin(), a.end(), comp);
			count = 0;
			memset(visited, 0, 10000 * sizeof(int));
			res = 0;
			while(count < n){
				count0 = count;
				i = 0;
				while(visited[i]){
					++i;
				}
				visited[i] = 1;
				++count;
				j = i + 1;
				while(true){
					if(j >= n){
						break;
					}else if(visited[j]){
						++j;
					}else if(a[i].l <= a[j].l && a[i].w <= a[j].w){
						visited[j] = 1;
						i = j;
						j = i + 1;
						++count;
					}else{
						++j;
					}
				}
				if(count > count0){
					++res;
				}
			}
			
			printf("%d\n", res);
		}
	}
	
	return 0;
}
