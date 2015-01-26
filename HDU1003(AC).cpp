#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
	int a;
	int mleft, mright, pos;
	int i, n;
	int t, ti;
	int sum, maxsum;
	
	while(true){
		if(scanf("%d", &t) != 1){
			break;
		}
		for(ti = 1; ti <= t; ++ti){
			if(ti > 1){
				printf("\n");
			}
			
			scanf("%d", &n);
			sum = 0;
			maxsum = -10000000;
			mleft = mright = pos = 1;
			for(i = 1; i <= n; ++i){
				scanf("%d", &a);
				if(sum < 0){
					sum = a;
					pos = i;
				}else{
					sum += a;
				}
				
				if(sum > maxsum){
					maxsum = sum;
					mleft = pos;
					mright = i;
				}
			}
			
			printf("Case %d:\n", ti);
			printf("%d %d %d\n", maxsum, mleft, mright);
		}
	}
	
	return 0;
}
