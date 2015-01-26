#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main()
{
	char str[6000];
	int i, j;
	int left, right;
	int pc;
	
	while(true){
		if(gets(str) == NULL){
			break;
		}else if(strlen(str) == 0){
			continue;
		}
		
		left = 0;
		right = strlen(str) - 1;
		pc = 0;
		for(i = left; i <= right; ++i){
			for(j = 1;  (i - j + 1) >= left && (i + j - 1) <= right; ++j){
				if(str[i - j + 1] == str[i + j - 1]){
					++pc;
				}else{
					break;
				}
			}
		}
		
		for(i = left; i <= right - 1; ++i){
			for(j = 1; (i - j + 1) >= left && (i + j) <= right; ++j){
				if(str[i - j + 1] == str[i + j]){
					++pc;
				}else{
					break;
				}
			}
		}
		
		printf("%d\n", pc);
	}
	
	return 0;
}
