#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAXN = 2005;
int f[MAXN];
int a[MAXN];
int b[MAXN];
int n;

int mymin(const int &a, const int &b)
{
	return (a < b ? a : b);
}

int main()
{
	int t, ti;
	int i;
	int h, m, s;

	while(scanf("%d", &t) == 1){
		for(ti = 0; ti < t; ++ti){
			scanf("%d", &n);
			memset(a, 0, MAXN * sizeof(int));
			memset(b, 0, MAXN * sizeof(int));
			memset(f, 0, MAXN * sizeof(int));
			for(i = 1; i <= n; ++i){
				scanf("%d", &a[i]);
			}
			for(i = 2; i <= n; ++i){
				scanf("%d", &b[i]);
			}
			f[0] = 0;
			f[1] = a[1];
			for(i = 2; i <= n; ++i){
				f[i] = mymin(f[i - 1] + a[i], f[i - 2] + b[i]);
			}

			h = 8 + f[n] / 3600;
			m = f[n] % 3600 / 60;
			s = f[n] % 60;

			if(h >= 8 && h <= 11){
				printf("%02d:%02d:%02d am\n", h, m, s);
			}else if(h == 12){
				printf("%02d:%02d:%02d pm\n", h, m, s);
			}else if(h >= 13 && h < 24){
				printf("%02d:%02d:%02d pm\n", h % 12, m, s);
			}else if(h >= 24 && h % 24 == 0){
				printf("%02d:%02d:%02d am\n", 12, m, s);
			}else{
				h %= 24;
				if(h >= 8 && h <= 11){
					printf("%02d:%02d:%02d am\n", h, m, s);
				}else if(h == 12){
					printf("%02d:%02d:%02d pm\n", h, m, s);
				}else{
					printf("%02d:%02d:%02d pm\n", h % 12, m, s);
				}
			}
		}
	}

	return 0;
}
