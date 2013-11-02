#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int myabs(int a)
{
    return (a > 0 ? a : -a);
}

int main()
{
    int istrue[12];
    int suspect[12];
    char left[3][10], right[3][10], res[3][10];
    int n, ni;
    int i, j, mi, msum;
    
    while(true){
        if(scanf("%d", &n) != 1){
            break;
        }
        for(ni = 0; ni < n; ++ni){
            memset(istrue, 0, 12 * sizeof(int));
            memset(suspect, 0, 12 * sizeof(int));
            for(i = 0; i < 3; ++i){
                scanf("%s%s%s", left[i], right[i], res[i]);
            }
            
            for(i = 0; i < 3; ++i){
                if(strcmp(res[i], "even") == 0){
                    for(j = 0; left[i][j]; ++j){
                        istrue[left[i][j] - 'A'] = 1;
                        istrue[right[i][j] - 'A'] = 1;
                    }
                }else if(strcmp(res[i], "up") == 0){
                    for(j = 0; left[i][j]; ++j){
                        ++suspect[left[i][j] - 'A'];
                        --suspect[right[i][j] - 'A'];
                    }
                }else if(strcmp(res[i], "down") == 0){
                    for(j = 0; j < left[i][j]; ++j){
                        --suspect[left[i][j] - 'A'];
                        ++suspect[right[i][j] - 'A'];
                    }
                }else{
                    //impossible
                }
            }
            
            mi = -1;
            msum = -1;
            for(i = 0; i < 12; ++i){
                if(istrue[i]){
                    continue;
                }
                if(msum <= myabs(suspect[i])){
                    mi = i;
                    msum = myabs(suspect[i]);
                }
            }
            
            if(suspect[mi] < 0){
                printf("%c is the counterfeit coin and it is light.\n", mi + 'A');
            }else{
                printf("%c is the counterfeit coin and it is heavy.\n", mi + 'A');
            }
        }
    }
    
    return 0;
}

