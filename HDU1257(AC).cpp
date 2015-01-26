#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

vector<int> va, vb;
int n;
int res;

int main()
{
	int i;
	int left, right, mid;

	while(scanf("%d", &n) == 1){
		if(n == 0){
			printf("0\n");
			continue;
		}
		va.clear();
		vb.clear();
		for(i = 0; i < n; ++i){
			scanf("%d", &res);
			va.push_back(res);
		}
		vb = vector<int>(va.size());
		res = 1;
		vb[res - 1] = va[0];
		for(i = 1; i < n; ++i){
			if(va[i] < vb[0]){
				vb[0] = va[i];
			}else if(va[i] == vb[res - 1]){
				continue;
			}else if(va[i] > vb[res - 1]){
				vb[res++] = va[i];
			}else{
				//binary search
				left = 0;
				right = res - 1;
				while(true){
					if(right - left <= 1){
						break;
					}
					mid = (left + right) / 2;
					if(va[i] < vb[mid]){
						right = mid;
					}else{
						left = mid;
					}
				}
				vb[right] = va[i];
			}
		}

		printf("%d\n", res);
	}

	return 0;
}
