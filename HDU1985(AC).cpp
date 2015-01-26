#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main()
{
	int case_count, case_no;
	char s[1000];
	double a;
	
	scanf("%d", &case_count);
	for(case_no = 1; case_no <= case_count; ++case_no){
		scanf("%lf%s", &a, s);
		if(strcmp(s, "kg") == 0){
			printf("%d %.4f lb\n", case_no, a * 2.2046);
		}else if(strcmp(s, "lb") == 0){
			printf("%d %.4f kg\n", case_no, a * 0.4536);
		}else if(strcmp(s, "l") == 0){
			printf("%d %.4f g\n", case_no, a * 0.2642);
		}else{
			printf("%d %.4f l\n", case_no, a * 3.7854);
		}
	}
	
	return 0;
}
