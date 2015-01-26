#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef struct item{
	char str[51];
	int inv;
}item;

void getinv(item *it)
{
	int i;
	int j;
	int len;
	
	len = strlen(it->str);
	it->inv = 0;
	for(i = 0; i < len - 1; ++i){
		for(j = i + 1; j < len; ++j){
			if(it->str[i] > it->str[j]){
				++(it->inv);
			}
		}
	}
}

void swap(int *x, int *y)
{
	int t;

	t = *x;
	*x = *y;
	*y = t;
}

int main()
{
	item a[110];
	int idx[110];
	int i, j;
	int n, m;
	int case_no;
	int case_count;
	
	scanf("%d", &case_count);
	for(case_no = 1; case_no <= case_count; ++case_no){
		if(case_no > 1){
			printf("\n");
		}
		
		scanf("%d%d", &n, &m);
		for(i = 0; i < m; ++i){
			scanf("%s", a[i].str);
			getinv(&a[i]);
		}
		
		for(i = 0; i < m; ++i){
			idx[i] = i;
		}

		for(i = 0; i < m - 1; ++i){
			for(j = i + 1; j < m; ++j){
				if(a[idx[i]].inv > a[idx[j]].inv){
					swap(&idx[i], &idx[j]);
				}
			}
		}

		for(i = 0; i < m; i++){
			printf("%s\n", a[idx[i]].str);
		}
	}
	
	return 0;
}
