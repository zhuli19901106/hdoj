#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int a[101][301];
int v[301];
int r[301];
int p, n;
int max_match;

int find_match(int x)
{
	int i;

	for(i = 1; i <= n; ++i){
		if(a[x][i] && !v[i]){
			v[i] = 1;
			if(r[i] == 0 || find_match(r[i])){
				r[i] = x;
				return true;
			}
		}
	}
	
	return false;
}

int main()
{
	int i, j, tmp, count;
	int case_count, case_no;
	
	scanf("%d", &case_count);
	for(case_no = 0; case_no < case_count; ++case_no){
		scanf("%d%d", &p, &n);
		memset(a, 0, 101 * 301 * sizeof(int));
		for(i = 1; i <= p; ++i){
			scanf("%d", &count);
			for(j = 1; j <= count; ++j){
				scanf("%d", &tmp);
				a[i][tmp] = 1;
			}
		}
		max_match = 0;
		memset(r, 0, 301 * sizeof(int));
		for(i = 1; i <= p; ++i){
			memset(v, 0, 301 * sizeof(int));
			if(find_match(i)){
				++max_match;
			}
		}
		
		//printf("MAX_MATCH = %d\n", max_match);
		if(max_match == p){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
	
	return 0;
}
