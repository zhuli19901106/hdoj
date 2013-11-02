#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
    int s;
    int ti;
    int res;
    const int fsize = 1860000;

    ti = 0;
    while(scanf("%d", &s) == 1 && s){
        ++ti;

        //compress the SHAR file
        s = (s + 1) / 2;

        //split it up
        s = s + (s + 1) / 2;
        res = (s + fsize - 1) / fsize;

        printf("File #%d\nJohn needs %d floppies.\n\n", ti, res);
    }

    return 0;
}

