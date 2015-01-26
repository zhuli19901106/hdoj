#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;

int a[10005];
int n;
int ll, rr;

int main()
{
	int i;

	while(scanf("%d", &n) == 1){
		for(i = 0; i < n; ++i){
			scanf("%d", &a[i]);
		}
		sort(a, a + n);
		ll = 0;
		rr = n - 1;
		printf("%d", a[n - 1]);
		ll = 0;
		rr = n - 2;
		while(true){
			if(ll > rr){
				break;
			}
			printf(" %d", a[ll]);
			++ll;
			if(ll > rr){
				break;
			}
			printf(" %d", a[rr]);
			--rr;
		}
		printf("\n");
	}

	return 0;
}
