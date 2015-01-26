#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int a[105][105], n;
int b[105];
int left, right, up;
int sum, msum;
bool all_negative;

int main()
{
	while(true){
		if(scanf("%d", &n) != 1){
			break;
		}
		msum = -99999999;
		all_negative = true;
		for(up = 0; up < n; ++up){
			for(left = 0; left < n; ++left){
				scanf("%d", &a[up][left]);
				if(a[up][left] > msum){
					msum = a[up][left];
				}
				if(a[up][left] >= 0){
					all_negative = false;
				}
			}
		}
		
		if(all_negative){
			printf("%d\n", msum);
			continue;
		}
		
		msum = -1;
		for(left = 0; left < n; ++left){
			memset(b, 0, 105 * sizeof(int));
			for(right = left; right < n; ++right){
				for(up = 0; up < n; ++up){
					b[up] += a[up][right];
				}
				
				//1-dimensional max substring problem here.
				sum = 0;
				for(up = 0; up < n; ++up){
					sum += b[up];
					if(sum < 0){
						sum = 0;
					}else if(sum > msum){
						msum = sum;
					}
				}
			}
		}
		
		printf("%d\n", msum);
	}
	
	return 0;
}
