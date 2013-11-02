#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <set>
using namespace std;

int main()
{
    set<int> s;
    int n1, n2;
    int tmp;
    int i;

    while(scanf("%d%d", &n1, &n2) == 2){
        s.clear();
        n1 = n1 + n2;
        for(i = 0; i < n1; ++i){
            scanf("%d", &tmp);
            s.insert(tmp);
        }

        for(set<int>::iterator sit = s.begin(); sit != s.end(); ++sit){
            if(sit == s.begin()){
                printf("%d", *sit);
            }else{
                printf(" %d", *sit);
            }
        }
        printf("\n");
    }

    return 0;
}

