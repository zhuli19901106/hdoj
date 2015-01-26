//#define MY_DEBUG
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

vector<int> v[201];
int b[201][201];
int clen[201];
int n, k;
int a[201];
int p[201];
char s[205], t[205];
int sc;

int main()
{
	int i, x;

	while(scanf("%d", &n) != EOF && n){
		for(i = 1; i <= n; ++i){
			scanf("%d", &a[i]);
		}
		memset(b, 0, 201 * 201 * sizeof(int));
		for(i = 1; i <= n; ++i){
			v[i].clear();
		}
		for(i = 1; i <= n; ++i){
			x = i;
			b[i][x] = 1;
			v[i].push_back(x);
			x = a[x];
			while(x != i){
				b[i][x] = 1;
				v[i].push_back(x);
				x = a[x];
			}
		}
		for(i = 1; i <= n; ++i){
			clen[i] = (int)v[i].size();
		}
		while(scanf("%d", &k) != EOF && k){
			getchar();
			gets(s + 1);
			sc = strlen(s + 1);
			while(sc < n){
				s[(sc + 1)] = ' ';
				++sc;
			}
			s[sc + 1] = 0;
			memset(p, 0, 201 * sizeof(int));
			for(i = 1; i <= n; ++i){
				p[v[i][k % clen[i]]] = i;
			}
#ifdef MY_DEBUG
			for(i = 1; i <= n; ++i){
				printf("%3d", i);
			}
			printf("\n");
			for(i = 1; i <= n; ++i){
				printf("%3d", a[i]);
			}
			printf("\n");
			for(i = 1; i <= n; ++i){
				printf("%3d", p[i]);
			}
			printf("\n");
#endif
			memset(t, 0, 205 * sizeof(char));
			for(i = 1; i <= n; ++i){
				t[i] = s[p[i]];
			}
			/*
			for(i = n; i >= 1; --i){
				if(t[i] != ' '){
					break;
				}
			}
			t[i + 1] = 0;
			*/
#ifdef MY_DEBUG			
			printf("%s\n", s + 1);
#endif
			printf("%s\n", t + 1);
		}
		printf("\n");
	}

	return 0;
}
