#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const char HaabMonth[19][10] = {
    "pop", "no", "zip", "zotz", "tzec",
    "xul", "yoxkin", "mol", "chen", "yax",
    "zac", "ceh", "mac", "kankin", "muan",
    "pax", "koyab", "cumhu", "uayet"
};
const char TzolkinName[20][10] = {
    "imix", "ik", "akbal", "kan", "chicchan",
    "cimi", "manik", "lamat", "muluk", "ok",
    "chuen", "eb", "ben", "ix", "mem",
    "cib", "caban", "eznab", "canac", "ahau"
};
int haab_year, haab_month, haab_day;
int tzolkin_year, tzolkin_name, tzolkin_day;

int main()
{
    char s[1000];
    int n, ni;
    int i;
    int count;
    
    while(true){
        if(scanf("%d", &n) != 1){
            break;
        }else{
            printf("%d\n", n);
        }
        for(ni = 0; ni < n; ++ni){
            scanf("%d", &haab_day);
            scanf("%1s", s);
            scanf("%s", s);
            for(i = 0; i < 19; ++i){
                if(strcmp(s, HaabMonth[i]) == 0){
                    haab_month = i;
                }
            }
            scanf("%d", &haab_year);
            count = haab_day + haab_month * 20 + haab_year * 365;
            tzolkin_year = count / 260;
            tzolkin_name = count % 20;
            tzolkin_day = count % 13;
            ++tzolkin_day;
            printf("%d %s %d\n", tzolkin_day, TzolkinName[tzolkin_name], tzolkin_year);
        }
    }
    
    return 0;
}

