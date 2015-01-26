#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

inline bool isleap(const int &n)
{
	return (n % 100 ? n % 4 == 0 : n % 400 == 0);
}

const char day_name[7][20] = {
	"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"
};
int md[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main()
{
	int i;
	int y, m, d;
	int dc;

	while(scanf("%d%d%d", &y, &m, &d) == 3){
		if(m < 1 || m > 12){
			printf("illegal\n");
			continue;
		}

		if(isleap(y)){
			md[2] = 29;
		}else{
			md[2] = 28;
		}

		if(d < 1 || d > md[m]){
			printf("illegal\n");
			continue;
		}

		dc = 0;
		dc += (y / 400) * (97 * 366 + 303 * 365);
		y = y % 400;
		for(i = 0; i < y; ++i){
			if(isleap(i)){
				dc += 366;
			}else{
				dc += 365;
			}
		}

		if(isleap(y)){
			md[2] = 29;
		}else{
			md[2] = 28;
		}
		for(i = 1; i < m; ++i){
			dc += md[i];
		}
		dc += (d - 1);

		printf("%s\n", day_name[(dc + 5) % 7]);
	}

	return 0;
}
