#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAXLEN = 500;
int ans[105][MAXLEN];
int temp[MAXLEN];

void print(int a[], const int &maxlen)
{
	int i;
	
	i = maxlen - 1;
	while(i >= 0 && a[i] == 0){
		--i;
	}
	if(i == -1){
		printf("0");
	}else{
		while(i >= 0){
			printf("%d", a[i]);
			--i;
		}
	}
}

void add(int a[], int b[], int c[], const int &maxlen)
{
	int i;
	
	for(i = 0; i < maxlen; ++i){
		c[i] = a[i] + b[i];
	}
	for(i = 0; i < maxlen - 1; ++i){
		c[i + 1] += c[i] / 10;
		c[i] %= 10;
	}
	c[maxlen - 1] %= 10;
}

void multiply(int a[], int b[], int c[], const int &maxlen)
{
	int i, j;
	
	memset(c, 0, maxlen * sizeof(int));
	for(i = 0; i < maxlen; ++i){
		if(a[i]){
			for(j = 0; j < maxlen; ++j){
				if(b[j]){
					c[i + j] += a[i] * b[j];
				}
			}
		}
	}
	
	for(i = 0; i < maxlen - 1; ++i){
		c[i + 1] += c[i] / 10;
		c[i] %= 10;
	}
	c[maxlen - 1] %= 10;
}

int main()
{
	int i, j;
	
	for(i = 0; i < 105; ++i){
		memset(ans[i], 0, MAXLEN * sizeof(int));
	}
	//f[0] = 1;
	//f[1] = 1;
	ans[0][0] = 1;
	ans[1][0] = 1;
	
	for(i = 2; i < 105; ++i){
		for(j = 0; j < i; ++j){
			multiply(ans[j], ans[i - 1 - j], temp, MAXLEN);
			add(ans[i], temp, ans[i], MAXLEN);
		}
	}
	/*
	for(i = 0; i < 105; ++i){
		print(ans[i], MAXLEN);
		printf("\n");
	}
	*/
	while(scanf("%d", &i) == 1 && i != -1){
		print(ans[i], MAXLEN);
		printf("\n");
	}
	
	return 0;
}
