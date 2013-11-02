#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
/*
-------------  -------------
|     |     |  |     |     |
|  4  |  1  |  |  2  |  3  |
|     |     |  |     |     |
-------------  -------------
*/
    int sn;
    int pn;
    int i;
    int tmp;
    
    while(true){
        scanf("%d", &pn);
        if(0 == pn){
            break;
        }
        
        sn = (pn + 3) / 4;
        printf("Printing order for %d pages:\n", pn);
        if(pn == 1){
            printf("Sheet 1, front: Blank, 1\n");
            continue;
        }
        for(i = 1; i <= sn; i++){
            printf("Sheet %d, front:", i);

            tmp = sn * 4 - 2 * (i - 1);
            if(tmp <= pn){
                printf(" %d,", tmp);
            }else{
                printf(" Blank,");
            }

            tmp = 2 * i - 1;
            if(tmp <= pn){
                printf(" %d\n", tmp);
            }else{
                printf(" Blank\n");
            }

            printf("Sheet %d, back :", i);

            tmp = 2 * i;
            if(tmp <= pn){
                printf(" %d,", tmp);
            }else{
                printf(" Blank,");
            }

            tmp = sn * 4 - 2 * (i - 1) - 1;
            if(tmp <= pn){
                printf(" %d\n", tmp);
            }else{
                printf(" Blank\n");
            }
        }
    }
    
    return 0;
}

