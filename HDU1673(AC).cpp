#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
	int n, i;
	int t, ti;
	int tmp;
	int min, max;
	
	while(true){
		if(scanf("%d", &t) != 1){
			break;
		}
		for(ti = 0; ti < t; ++ti){
			scanf("%d", &n);
			min = -1;
			max = -1;
			for(i = 0; i < n; ++i){
				scanf("%d", &tmp);
				if(min == -1 || tmp < min){
					min = tmp;
				}

				if(max == -1 || tmp > max){
					max = tmp;
				}
			}
			
			printf("%d\n", 2 * (max - min));
		}
	}
	
	return 0;
}
