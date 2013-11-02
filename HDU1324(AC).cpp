#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int find(int a[], int n, int key)
{
    int i;

    for(i = 0; i < n; i++){
        if(a[i] == key){
            return i;
        }
    }

    return -1;
}

int main()
{
    int z, i, m, l;
    int a[10001];
    int j;
    int pos;
    int casecount;
    
    casecount = 0;
    while(true){
        scanf("%d%d%d%d", &z, &i, &m, &l);
        if(z == 0 && i == 0 && m == 0 && l == 0){
            break;
        }else{
            casecount++;
            j = 0;
            a[j] = l;
            j++;
            while(true){
                l = (z * l + i) % m;
                pos = find(a, j, l);
                if(pos == -1){
                    a[j] = l;
                    j++;
                }else{
                    printf("Case %d: %d\n", casecount, j - pos);
                    break;
                }
            }
        }
    }

    return 0;
}

