#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

int main()
{
    int dec[4];
    int duo[4];
    int hex[4];
    int sumdec;
    int sumduo;
    int sumhex;
    int num;
    int n0;

    for(num = 1000; num < 10000; num++)
    {
        n0 = num;
        dec[0] = n0 % 10;
        n0 = (n0 - dec[0]) / 10;
        dec[1] = n0 % 10;
        n0 = (n0 - dec[1]) / 10;
        dec[2] = n0 % 10;
        n0 = (n0 - dec[2]) / 10;
        dec[3] = n0 % 10;

        n0 = num;
        duo[0] = n0 % 12;
        n0 = (n0 - duo[0]) / 12;
        duo[1] = n0 % 12;
        n0 = (n0 - duo[1]) / 12;
        duo[2] = n0 % 12;
        n0 = (n0 - duo[2]) / 12;
        duo[3] = n0 % 12;

        n0 = num;
        hex[0] = n0 % 16;
        n0 = (n0 - hex[0]) / 16;
        hex[1] = n0 % 16;
        n0 = (n0 - hex[1]) / 16;
        hex[2] = n0 % 16;
        n0 = (n0 - hex[2]) / 16;
        hex[3] = n0 % 16;

        sumdec = dec[0] + dec[1] + dec[2] + dec[3];
        sumduo = duo[0] + duo[1] + duo[2] + duo[3];
        sumhex = hex[0] + hex[1] + hex[2] + hex[3];

        if(sumdec == sumduo && sumduo == sumhex)
        {
            printf("%d\n", num);
        }
    }

    return 0;
}

