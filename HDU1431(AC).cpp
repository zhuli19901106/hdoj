#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int p[10000];
int pc;

bool isprime(int n)
{
	int i;

	if(n < 2){
		return false;
	}

	for(i = 2; i <= n / i; ++i){
		if(n % i == 0){
			return false;
		}
	}

	return true;
}

void reverse(char s[])
{
	int i, len;
	char ch;

	i = 0;
	len = strlen(s);
	while(i < len - 1 - i){
		ch = s[i];
		s[i] = s[len - 1 - i];
		s[len - 1 - i] = ch;
		++i;
	}
}

void get_palidrome(int n, int &x, int &y)
{
	char s1[50], s2[50], s3[50];

	sprintf(s1, "%d", n);
	strcpy(s2, s1);
	reverse(s2);

	strcpy(s3, s1);
	strcat(s3, s2);
	sscanf(s3, "%d", &x);

	strcpy(s3, s1);
	strcat(s3, s2 + 1);
	sscanf(s3, "%d", &y);
}

int main()
{
	int i;
	int x, y;
	int ix, iy;
	int left, mid, right;

	pc = 0;
	for(i = 1; i <= 9999; ++i){
		get_palidrome(i, x, y);
		if(isprime(x)){
			p[pc++] = x;
		}
		if(isprime(y)){
			p[pc++] = y;
		}
	}
	sort(p, p + pc);

	while(scanf("%d%d", &x, &y) == 2){
		left = 0;
		right = pc - 1;
		while(true){
			if(right - left <= 1){
				break;
			}
			mid = (left + right) / 2;
			if(p[mid] >= x){
				right = mid;
			}else{
				left = mid;
			}
		}
		ix = right;
		if(x <= p[0]){
			ix = 0;
		}

		left = 0;
		right = pc - 1;
		while(true){
			if(right - left <= 1){
				break;
			}
			mid = (left + right) / 2;
			if(p[mid] <= y){
				left = mid;
			}else{
				right = mid;
			}
		}
		iy = left;
		if(y >= p[pc - 1]){
			iy = pc - 1;
		}

		for(i = ix; i <= iy; ++i){
			printf("%d\n", p[i]);
		}
		printf("\n");
	}

	return 0;
}
