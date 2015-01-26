#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

bool comp(const int &a, const int &b)
{
	return a > b;
}

int main()
{
	vector<int> a;
	int n;
	int i;
	int t, ti;
	int sum;
	
	while(true){
		if(scanf("%d", &t) != 1){
			break;
		}
		
		for(ti = 0; ti < t; ++ti){
			scanf("%d", &n);
			a.clear();
			for(i = 0; i < n; ++i){
				scanf("%d", &sum);
				a.push_back(sum);
			}
			sort(a.begin(), a.end(), comp);
			sum = 0;
			for(i = 2; i < n; i += 3){
				sum += a[i];
			}
			printf("%d\n", sum);
		}
	}
	
	return 0;
}
