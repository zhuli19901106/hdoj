#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int a[40005];
int b[40005];
int bc;
int n;

int main()
{
	int i;
	int left, mid, right;
	int t, ti;

	while(scanf("%d", &t) == 1){
		for(ti = 0; ti < t; ++ti){
			scanf("%d", &n);
			for(i = 0; i < n; ++i){
				scanf("%d", &a[i]);
			}
			bc = 0;
			b[bc++] = a[0];
			for(i = 1; i < n; ++i){
				if(a[i] < b[0]){
					b[0] = a[i];
				}else if(a[i] > b[bc - 1]){
					b[bc++] = a[i];
				}else if(a[i] == b[bc - 1]){
					continue;
				}else{
					left = 0;
					right = bc - 1;
					while(true){
						if(right - left <= 1){
							break;
						}
						mid = (left + right) / 2;
						if(a[i] >= b[mid]){
							left = mid;
						}else{
							right = mid;
						}
					}

					if(a[i] > b[left]){
						b[right] = a[i];
					}
				}
			}
			printf("%d\n", bc);
		}
	}

	return 0;
}
