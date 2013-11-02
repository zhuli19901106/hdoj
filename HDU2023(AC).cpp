#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int n, m;
double a[50][5];
double ave_stu[50];
double ave_course[5];
int count;

int main()
{
    int i, j;

    while(scanf("%d%d", &n, &m) == 2){
        memset(ave_stu, 0, 50 * sizeof(double));
        memset(ave_course, 0, 5 * sizeof(double));
        for(i = 0; i < n; ++i){
            for(j = 0; j < m; ++j){
                scanf("%lf", &a[i][j]);
                ave_stu[i] += a[i][j];
                ave_course[j] += a[i][j];
            }
        }
        for(i = 0; i < n; ++i){
            ave_stu[i] /= m;
        }
        for(i = 0; i < m; ++i){
            ave_course[i] /= n;
        }

        count = 0;
        for(i = 0; i < n; ++i){
            for(j = 0; j < m; ++j){
                if(a[i][j] < ave_course[j]){
                    break;
                }
            }
            if(j == m){
                ++count;
            }
        }

        for(i = 0; i < n; ++i){
            if(i == 0){
                printf("%.2f", ave_stu[i]);
            }else{
                printf(" %.2f", ave_stu[i]);
            }
        }
        printf("\n");
        for(i = 0; i < m; ++i){
            if(i == 0){
                printf("%.2f", ave_course[i]);
            }else{
                printf(" %.2f", ave_course[i]);
            }
        }
        printf("\n");
        printf("%d\n\n", count);
    }

    return 0;
}

