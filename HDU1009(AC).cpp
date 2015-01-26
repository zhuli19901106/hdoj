#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef struct item{
	double f;
	double j;
	double r;
}Item;

int comp(const void *a, const void *b)
{
	return ((const item *)b)->r > ((const item *)a)->r;
}

int main()
{
	Item a[1005];
	int index[1005];
	int i, j;
	int n, m;
	double fm;
	double max_amount;
	
	while(true){
		scanf("%d%d", &m, &n);
		fm = m;
		if(-1 == m && -1 == n){
			break;
		}
		for(i = 0; i < n; ++i){
			scanf("%lf%lf", &a[i].j, &a[i].f);
			if(0.0 == a[i].f){
				a[i].r = -1;
			}else{
				a[i].r = a[i].j / a[i].f;
			}
		}

		for(i = 0; i < n; ++i){
			index[i] = i;
		}
		for(i = 0; i < n - 1; ++i){
			for(j = i + 1; j < n; ++j){
				if(a[index[i]].r > a[index[j]].r){
					index[i] ^= index[j] ^= index[i] ^= index[j];
				}
			}
		}

		max_amount = 0.0;
		for(i = 0; i < n; ++i){
			if(a[index[i]].r == -1.0){
				max_amount = max_amount + a[index[i]].j;
			}else{
				break;
			}
		}
		
		for(i = n - 1; i >= 0; --i){
			if(fm <= 0.0 || a[index[i]].r == -1.0){
				break;
			}else if(fm >= a[index[i]].f){
				max_amount = max_amount + a[index[i]].j;
				fm = fm - a[index[i]].f;
			}else{
				max_amount = max_amount + fm * a[index[i]].j / a[index[i]].f;
				fm = 0.0;
			}
		}
		
		printf("%0.3f\n", max_amount);
	}
	
	return 0;
}
