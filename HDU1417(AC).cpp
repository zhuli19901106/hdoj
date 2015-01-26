#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef struct cube{
public:
	int x1, x2;
	int y1, y2;
	int z1, z2;
}Cube;
Cube a[1005];
int n;
long long int v;

int max(const int a, const int b)
{
	return (a > b ? a : b);
}

int min(const int a, const int b)
{
	return (a < b ? a : b);
}

int main()
{
	int i;
	Cube res, tmp;
	int l;

	while(scanf("%d", &n) == 1 && n){
		for(i = 0; i < n; ++i){
			scanf("%d%d%d%d", &a[i].x1, &a[i].y1, &a[i].z1, &l);
			a[i].x2 = a[i].x1 + l;
			a[i].y2 = a[i].y1 + l;
			a[i].z2 = a[i].z1 + l;
		}
		res = Cube(a[0]);
		v = 1LL * (res.x2 - res.x1) * (res.y2 - res.y1) * (res.z2 - res.z1);

		for(i = 1; i < n; ++i){
			tmp.x1 = max(res.x1, a[i].x1);
			tmp.y1 = max(res.y1, a[i].y1);
			tmp.z1 = max(res.z1, a[i].z1);
			tmp.x2 = min(res.x2, a[i].x2);
			tmp.y2 = min(res.y2, a[i].y2);
			tmp.z2 = min(res.z2, a[i].z2);

			if(tmp.x1 >= tmp.x2 || tmp.y1 >= tmp.y2 || tmp.z1 >= tmp.z2){
				v = 0;
			}else{
				res = tmp;
				v = 1LL * (res.x2 - res.x1) * (res.y2 - res.y1) * (res.z2 - res.z1);
			}
		}

		printf("%lld\n", v);
	}

	return 0;
}
