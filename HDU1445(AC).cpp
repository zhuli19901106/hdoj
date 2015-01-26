#define _CRT_SECURE_NO_WARNINGS
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

//Ignore Charley, but think about the one that arrives at the school first, Charley will always be with that guy.

int main()
{
	char str[1000];
	double speed;
	double time;
	const double s = 4500;
	int n;
	double min_time;

	while(true){
		if(gets(str) == NULL){
			break;
		}else if(sscanf(str, "%d", &n), 0 == n){
			break;
		}
		min_time = -1;
		while(n--){
			gets(str);
			sscanf(str, "%lf\t%lf", &speed, &time);
			if(time < 0){
				continue;
			}
			speed = speed / 3.6;
			time = time + s /speed;
			if(min_time == -1.0 || min_time > time){
				min_time = time;
			}
		}
		
		printf("%d\n", (int)ceil(min_time));
	}

	return 0;
}
