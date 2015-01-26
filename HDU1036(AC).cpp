#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

char str[100];
int n;
double d;

int main()
{
	int ss;
	int h, m, s;
	int tn;
	int i, j, len;
	bool valid;

	scanf("%d%lf", &n, &d);
	while(scanf("%d", &tn) == 1){
		ss = 0;
		valid = true;
		for(i = 0; i < n; ++i){
			scanf("%s", str);
			if(!valid){
				continue;
			}
			len = strlen(str);
			for(j = 0; j < len; ++j){
				if(str[j] == '-'){
					valid = false;
					break;
				}
			}
			if(!valid){
				continue;
			}

			sscanf(str, "%d", &h);
			j = 0;
			while(j < len && str[j] != ':'){
				++j;
			}
			++j;
			sscanf(str + j, "%d", &m);
			while(j < len && str[j] != ':'){
				++j;
			}
			++j;
			sscanf(str + j, "%d", &s);

			ss += h * 3600 + m * 60 + s;
		}

		printf("%3d: ", tn);
		if(valid){
			ss = (int)(ss * 1.0 / d + 0.5);
			m = ss / 60;
			s = ss % 60;
			printf("%d:%02d min/km\n", m, s);
		}else{
			printf("-\n");
		}
	}

	return 0;
}
