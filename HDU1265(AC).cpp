#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
using namespace std;

int main()
{
    int t, ti;
    long x;
    float m;
    
    while(cin >> t){
        for(ti = 0; ti < t; ++ti){
            cin >> m;
            memcpy(&x, &m, 4);
            printf("%lX\n",x);
        }
    }

    return 0;
}

