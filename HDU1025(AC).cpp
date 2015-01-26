#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

typedef struct st{
	int x;
	int y;
}st;
vector<st> v;
vector<st> v1;

int n;
int a[500005];
int ac;

bool comparator(const st &a, const st &b)
{
	if(a.x == b.x){
		return a.y < b.y;
	}else{
		return a.x < b.x;
	}
}

int main()
{
	int i, j;
	int len;
	st vst;
	int left, mid, right;

	int ti;

	ti = 0;
	while(scanf("%d", &n) == 1){
		++ti;
		v.clear();
		for(i = 0; i < n; ++i){
			scanf("%d%d", &vst.x, &vst.y);
			v.push_back(vst);
		}
		sort(v.begin(), v.end(), comparator);

		v1.clear();
		len = (int)v.size();
		i = 0;
		while(true){
			if(i >= len){
				break;
			}
			v1.push_back(v[i]);
			j = i + 1;
			while(j < len && v[j].x == v[i].x){
				++j;
			}
			i = j;
		}
		v.clear();

		ac = 0;
		a[ac++] = v1[0].y;
		len = (int)v1.size();
		for(i = 1; i < len; ++i){
			if(v1[i].y < a[0]){
				a[0] = v1[i].y;
			}else if(v1[i].y > a[ac - 1]){
				a[ac++] = v1[i].y;
			}else if(v1[i].y == a[ac - 1]){
				continue;
			}else{
				left = 0;
				right = ac - 1;
				while(true){
					if(right - left <= 1){
						break;
					}
					mid = (left + right) / 2;
					if(v1[i].y >= a[mid]){
						left = mid;
					}else{
						right = mid;
					}
				}
				if(v1[i].y > a[left]){
					a[right] = v1[i].y;
				}
			}
		}
		v1.clear();
		printf("Case %d:\n", ti);
		if(ac > 1){
			printf("My king, at most %d roads can be built.\n", ac);
		}else{
			printf("My king, at most %d road can be built.\n", ac);
		}
		printf("\n");
	}

	return 0;
}
