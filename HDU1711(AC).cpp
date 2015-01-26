#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

const int MAXN = 1000005;
const int MAXM = 10005;
int n, m;
int s[MAXN];
int p[MAXM];
int nextv[MAXM];
int res;

void get_nextval(const int pat[], const int plen, int nextv[])
{
	int i, j;

	if(pat == NULL || nextv == NULL){
		return;
	}

	i = 0;
	nextv[i] = -1;
	j = -1;
	while(i < plen - 1){
		if(j == -1 || pat[i] == pat[j]){
			++i;
			++j;
			if(pat[i] != pat[j]){
				nextv[i] = j;
			}else{
				nextv[i] = nextv[j];
			}
		}else{
			j = nextv[j];
		}
	}
}

int kmp_search(const int src[], const int slen, const int pat[], const int plen, const int nextv[])
{
	int i, j;

	i = j = 0;
	while(i < slen && j < plen){
		if(j == -1 || src[i] == pat[j]){
			++i;
			++j;
		}else{
			j = nextv[j];
		}
	}

	if(j >= plen){
		return i - plen;
	}else{
		return -1;
	}
}

int main()
{
	int t, ti;
	int i;

	while(scanf("%d", &t) == 1){
		for(ti = 0; ti < t; ++ti){
			scanf("%d%d", &n, &m);
			for(i = 0; i < n; ++i){
				scanf("%d", &s[i]);
			}
			for(i = 0; i < m; ++i){
				scanf("%d", &p[i]);
			}
			get_nextval(p, m, nextv);
			res = kmp_search(s, n, p, m, nextv);
			if(res >= 0){
				printf("%d\n", res + 1);
			}else{
				printf("-1\n");
			}
		}
	}

	return 0;
}
