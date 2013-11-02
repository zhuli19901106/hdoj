#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
    int n;
    int *ns;
    double *lens;
    int i;
    int counter;

    ns = (int *)malloc(100000 * sizeof(int));
    lens = (double *)malloc(100000 * sizeof(double));
    counter = 0;
    while(1)
    {
        if(scanf("%d", &n) != 1)
        {
            break;
        }
        else
        {
            ns[counter] = n;
        }

        lens[counter] = 0;
        for(i = 1; i <= ns[counter]; i++)
        {
            lens[counter] = lens[counter] + 1.0 / (2 * i);
        }
        counter++;
    }

    printf("# Cards  Overhang\n");
    for(i = 0; i < counter; i++)
    {
        printf ("%5d%10.3f\n", ns[i], lens[i]);
    }
    free(ns);
    free(lens);
    return 0;
}

