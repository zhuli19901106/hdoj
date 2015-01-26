#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main()
{
	int n[7];
	int i, j, k;
	int case_no;
	int a[500];
	int sum;
	bool success;
	
	case_no = 0;
	while(true){
		if(scanf("%d%d%d%d%d%d", &n[1], &n[2], &n[3], &n[4], &n[5], &n[6]) != 6){
			break;
		}else if(
			n[1] == 0 &&
			n[2] == 0 &&
			n[3] == 0 &&
			n[4] == 0 &&
			n[5] == 0 &&
			n[6] == 0){
			break;
		}else{
			++case_no;
		}
		
		sum = 0;
		for(i = 1; i <= 6; ++i){
			sum += n[i] * i;
		}
		if(sum % 2){
			printf("Collection #%d:\n", case_no);
			printf("Can't be divided.\n");
			printf("\n");
			continue;
		}

		success = false;
		if(n[1] >= 6){
			success = true;
		}
		if(n[2] >= 5){
			n[2] = 3 + (n[2] + 1) % 2;
		}
		if(n[3] >= 9){
			n[3] = 7 + (n[3] + 1) % 2;
		}
		if(n[4] >= 9){
			n[4] = 7 + (n[4] + 1) % 2;
		}
		if(n[5] >= 13){
			n[5] = 11 + (n[5] + 1) % 2;
		}
		if(n[6] >= 8){
			n[6] = 6 + n[6] % 2;
		}
		
		if(!success){
			sum = 0;
			for(i = 1; i <= 6; ++i){
				sum += n[i] * i;
			}
			sum /= 2;
			memset(a, 0, 500 * sizeof(int));
			a[0] = 1;
			for(i = 1; i <= 6; ++i){
				for(j = 1; j <= n[i]; ++j){
					for(k = sum; k >= j * i; --k){
						if(!a[k] && a[k - i]){
							a[k] = 1;
						}
					}
				}
			}

			if(a[sum]){
				success = true;
			}
		}

		printf("Collection #%d:\n", case_no);
		if(success){
			printf("Can be divided.\n");
		}else{
			printf("Can't be divided.\n");
		}
		printf("\n");
	}
	
	return 0;
}
