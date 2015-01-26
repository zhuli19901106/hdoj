#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;

int comp(const void *a, const void *b)
{
	return *(const int *)a - *(const int *)b;
}

int main()
{
	int k[1200];
	int t[1200];
	int n;
	int kl, kr;
	int tl, tr;
	int win;
	int i;
	
	while(true){
		if(scanf("%d", &n) != 1){
			break;
		}else if(0 == n){
			break;
		}
		
		for(i = 0; i < n; ++i){
			scanf("%d", &t[i]);
		}
		
		for(i = 0; i < n; ++i){
			scanf("%d", &k[i]);
		}
		
		qsort(t, n, sizeof(int), comp);
		qsort(k, n, sizeof(int), comp);

		win = 0;
		tl = kl = 0;
		tr = kr = n - 1;
		while(tl <= tr && kl <= kr){
			if(t[tr] > k[kr]){
				--tr;
				--kr;
				++win;
			}else if(t[tr] < k[kr]){
				++tl;
				--kr;
				--win;
			}else{
				if(t[tl] > k[kl]){
					++tl;
					++kl;
					++win;
				}else if(t[tl] < k[kl]){
					++tl;
					--kr;
					--win;
				}else{
					if(t[tl] == k[kr]){
						break;
					}
					++tl;
					--kr;
					--win;
				}
			}
		}

		printf("%d\n", win * 200);
	}
	
	return 0;
}
