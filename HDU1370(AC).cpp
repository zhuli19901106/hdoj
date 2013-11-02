#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
    int p;
    int e;
    int i;
    int d;

    const int tp = 23;
    const int te = 28;
    const int ti = 33;
    int kp;
    int ke;
    int ki;
    int n;
    int ni;
    int next;
    int ci;

    while(true){
        if(scanf("%d", &n) != 1){
            break;
        }
        for(ni = 0; ni < n; ni++)
        {
            if(ni > 0)
            {
                printf("\n");
            }

            ci = 0;
            while(true)
            {
                scanf("%d%d%d%d", &p, &e, &i, &d);

                if(p == -1 && e == -1 && i == -1 && d == -1)
                {
                    break;
                }
                else
                {
                    ci++;
                }

                kp = te * ti;
                while(kp % tp != 1)
                {
                    kp += te * ti;
                }

                ke = ti * tp;
                while(ke % te != 1)
                {
                    ke += ti * tp;
                }

                ki = tp * te;
                while(ki % ti != 1)
                {
                    ki += tp * te;
                }

                next = (kp * p + ke * e + ki * i) % (tp * te * ti);
                if(d == next)
                {
                    printf("Case %d: the next triple peak occurs in %d days.\n", ci, tp * te * ti);
                }
                else
                {
                    printf("Case %d: the next triple peak occurs in %d days.\n", ci, (next - d + tp * te * ti) % (tp * te * ti));
                }
            }
        }
    }

    return 0;
}

