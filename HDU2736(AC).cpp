#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef struct pair_t{
	char first;
	char second;
}pair_t;

int comparator(const void *a, const void *b)
{
	return (((pair_t *)a)->first - ((pair_t *)b)->first) * 100 + (((pair_t *)a)->second - ((pair_t *)b)->second);
}

int main()
{
	char s[1000];
	pair_t a[100];
	int i;
	int j;
	int len;
	bool surprise;

	while(true){
		if(gets(s) == NULL){
			break;
		}else if(strcmp(s, "*") == 0){
			break;
		}

		len = strlen(s);
		surprise = true;
		for(i = 1; surprise == true && i <= len - 2; i++){
			for(j = 0; j <= len - i - 1; j++){
				a[j].first = s[j];
				a[j].second = s[j + i];
			}

			qsort(a, len - i, sizeof(pair_t), comparator);
			for(j = 0; surprise == true && j < len - i - 1; j++){
				if(a[j].first == a[j + 1].first && a[j].second == a[j + 1].second){
					surprise = false;
					break;
				}
			}
		}

		if(surprise == true){
			printf("%s is surprising.\n", s);
		}else{
			printf("%s is NOT surprising.\n", s);
		}
	}

	return 0;
}
