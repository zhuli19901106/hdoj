#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

typedef long long int LL;
LL a[10000];
int n;
int res;

typedef struct st{
public:
	LL key;
	int count;
	st(const LL _key, int _count)
	{
		key = _key;
		count = _count;
	}
}st;
vector<st> vv;

int main()
{
	int t[5];
	int i, j;

	while(scanf("%d", &n) == 1 && n){
		memset(a, 0, 10000 * sizeof(LL));
		for(i = 0; i < n; ++i){
			scanf("%d%d%d%d%d", &t[0], &t[1], &t[2], &t[3], &t[4]);
			sort(t, t + 5);
			a[i] = 0;
			for(j = 0; j < 5; ++j){
				a[i] *= 1000;
				a[i] += t[j];
			}
		}
		sort(a, a + n);

		i = 0;
		res = 0;
		vv.clear();
		while(true){
			if(i >= n){
				break;
			}
			j = i + 1;
			while(j < n && a[j] == a[i]){
				++j;
			}
			vv.push_back(st(a[i], j - i));
			if(j - i > res){
				res = j - i;
			}
			i = j;
		}

		j = 0;
		for(i = 0; i < (int)vv.size(); ++i){
			if(vv[i].count == res){
				++j;
			}
		}
		printf("%d\n", res * j);
	}

	return 0;
}
