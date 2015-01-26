#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
	int i;
	double a[12];
	double average;

	average = 0;
	for(i = 0; i < 12; i++)
	{
		scanf("%lf", &a[i]);
		average = average + a[i];
	}
	average = average / 12.0;
	printf("$%0.2f\n", average);

	return 0;
}
