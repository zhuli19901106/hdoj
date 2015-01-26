#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;

int a[20005];
int ac;
int b[20005];
int bc;
long long int cost;

int main()
{
	int i, j;

	while(scanf("%d%d", &ac, &bc) == 2 && (ac || bc)){
		for(i = 0; i < ac; ++i){
			scanf("%d", &a[i]);
		}
		for(i = 0; i < bc; ++i){
			scanf("%d", &b[i]);
		}
		sort(a, a + ac);
		sort(b, b + bc);
		i = j = 0;
		cost = 0;
		while(i < ac && j < bc){
			if(b[j] >= a[i]){
				cost += b[j];
				++i;
				++j;
			}else{
				++j;
			}
		}
		if(i >= ac){
			printf("%lld\n", cost);
		}else{
			printf("Loowater is doomed!\n");
		}
	}

	return 0;
}
