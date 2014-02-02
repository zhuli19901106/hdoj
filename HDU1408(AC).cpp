#define _CRT_SECURE_NO_WARNINGS
#include <cmath>
#include <cstdio>
using namespace std;

int main()
{
    int res, sec, tt, i;
    double v, d;

    while(scanf("%lf%lf", &v, &d) == 2){
		sec = (int)ceil(v / d);
		tt = 0;
		res = 0;
		for (i = 1; ; ++i) {
			tt += i;
			if (tt >= sec) {
				res += (sec - (tt - i));
				break;
			} else {
				res += i;
				++res;
			}
		}
        printf("%d\n", res);
    }

    return 0;
}