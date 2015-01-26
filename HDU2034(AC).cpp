#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;

int a[200], b[200];
int c[200], cc;
int n, m;

int my_bsearch(const int a[], int n, int key)
{
	int left, mid, right;

	left = 0;
	right = n - 1;
	while(left <= right){
		mid = (left + right) / 2;
		if(key < a[mid]){
			right = mid - 1;
		}else if(key > a[mid]){
			left = mid + 1;
		}else{
			return mid;
		}
	}

	return -1;
}

int main()
{
	int i;

	while(scanf("%d%d", &n, &m) == 2 && (n || m)){
		for(i = 0; i < n; ++i){
			scanf("%d", &a[i]);
		}
		for(i = 0; i < m; ++i){
			scanf("%d", &b[i]);
		}
		sort(a, a + n);
		sort(b, b + m);
		cc = 0;
		for(i = 0; i < n; ++i){
			if(my_bsearch(b, m, a[i]) == -1){
				c[cc++] = a[i];
			}
		}

		if(cc > 0){
			for(i = 0; i < cc; ++i){
				printf("%d ", c[i]);
			}
			printf("\n");
		}else{
			printf("NULL\n");
		}
	}

	return 0;
}
