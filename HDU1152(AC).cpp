#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

const int MAXN = 200005;
int cx, cy;
int x[MAXN], y[MAXN];
int n;
int ss, so;

int main()
{
	int i;

	while(scanf("%d", &n) == 1 && n){
		for(i = 0; i < n; ++i){
			scanf("%d%d", &x[i], &y[i]);
		}

		cx = x[(n - 1) / 2];
		cy = y[(n - 1) / 2];

		ss = so = 0;
		for(i = 0; i < n; ++i){
			if(x[i] > cx){
				if(y[i] > cy){
					++ss;
				}else if(y[i] < cy){
					++so;
				}
			}else if(x[i] < cx){
				if(y[i] > cy){
					++so;
				}else if(y[i] < cy){
					++ss;
				}
			}
		}

		printf("%d %d\n", ss, so);
	}

	return 0;
}
