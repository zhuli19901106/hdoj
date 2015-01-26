#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;

typedef struct stime{
	int hour;
	int minute;
	double hangle;
	double mangle;
	double angle;
}stime;

bool comparator(const stime &a, const stime &b)
{
	if(a.angle == b.angle){
		return a.hour * 60 + a.minute < b.hour * 60 + b.minute;
	}else{
		return a.angle < b.angle;
	}
}

int main()
{
	int i;
	int j;
	int n;
	vector<stime> a;
	stime st;
	char s[1000];

	while(true){
		if(scanf("%d", &n) != 1){
			break;
		}
		for(i = 0; i < n; i++)
		{
			a.clear();
			for(j = 0; j < 5; j++)
			{
				scanf("%02d%1s%02d", &st.hour, s, &st.minute);
				st.mangle = 6 * st.minute;
				st.hangle = 30 * (st.hour % 12) + 30 * st.minute / 60.0;
				st.angle = st.hangle - st.mangle;
				if(st.angle > -360 && st.angle <= -180)
				{
					st.angle = st.angle + 360;
				}
				else if(st.angle > -180 && st.angle <= 0)
				{
					st.angle = -st.angle;
				}
				else if(st.angle > 0 && st.angle <= 180)
				{
					st.angle = st.angle;
				}
				else if(st.angle > 180 && st.angle <= 360)
				{
					st.angle = 360 - st.angle;
				}
				a.push_back(st);
			}

			sort(a.begin(), a.end(), comparator);
			printf("%02d:%02d\n", a[2].hour, a[2].minute);
		}
	}

	return 0;
}
