#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef unsigned long dword;

int main()
{
    int i,j;
    int d;
    int first;
    dword *A=NULL;
    dword mask[32]={
        0x00000001,0x00000002,0x00000004,0x00000008,
        0x00000010,0x00000020,0x00000040,0x00000080,
        0x00000100,0x00000200,0x00000400,0x00000800,
        0x00001000,0x00002000,0x00004000,0x00008000,
        0x00010000,0x00020000,0x00040000,0x00080000,
        0x00100000,0x00200000,0x00400000,0x00800000,
        0x01000000,0x02000000,0x04000000,0x08000000,
        0x10000000,0x20000000,0x40000000,0x80000000
    };

    scanf("%d",&d);
    if(d<=0)
        return 1;

    A=(dword *)malloc(d*sizeof(dword));
    if(A==NULL)
        return 1;

    for(i=0;i<d;i++)
    {
        scanf("%lu",&A[i]);
        first=0;
        for(j=0;j<32;j++)
            if((!!(A[i]&mask[j]))!=0)
            {
                printf((first?" %d":"%d"),j);
                if(first==0)
                    first=1;
            }
        if(first==1)
            putchar('\n');
    }
    free(A);
    return 0;
}

