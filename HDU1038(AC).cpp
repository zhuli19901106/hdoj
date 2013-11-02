#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

int main()
{
    const double pi = 3.1415927;
    int rev;
    double d;
    double time;
    double dist;
    double speed;
    int n;

    n = 0;
    while(1)
    {
        scanf("%lf%d%lf", &d, &rev, &time);
        if(rev == 0)
        {
            break;
        }
        else
        {
            n++;
        }

        dist = rev * pi * d / 5280 / 12;
        time = time / 3600;
        speed = dist / time;

        printf("Trip #%d: %0.2f %0.2f\n", n, dist, speed);
    }

    return 0;
}

