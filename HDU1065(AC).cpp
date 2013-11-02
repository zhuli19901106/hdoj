#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

int main()
{
    double x;
    double y;
    double r2;
    const double pi = 3.1415926;

    int t;
    int i;
    int year;

    while(true)
    {
        if(scanf("%d", &t) != 1)
        {
            break;
        }

        for(i = 0; i < t; i++)
        {
            scanf("%lf%lf", &x, &y);

            r2 = x * x + y * y;
            year = (int)floor(r2 * pi / 100.0) + 1;

            printf("Property %d: This property will begin eroding in year %d.\n", i + 1, year);
        }
        printf("END OF OUTPUT.\n");
    }

    return 0;
}

