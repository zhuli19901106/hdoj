#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

double xx1, yy1, xx2, yy2;

int main()
{
    while(scanf("%lf%lf%lf%lf", &xx1, &yy1, &xx2, &yy2) == 4){
        printf("%.2f\n", sqrt((xx1 - xx2) * (xx1 - xx2) + (yy1 - yy2) * (yy1 - yy2)));
    }

    return 0;
}

