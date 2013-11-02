#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <queue>
using namespace std;
#define MAX 10000

bool inbound(int x, int y)
{
    return (x >= 0 && x <= 7) && (y >= 0 && y <= 7);
}

void getcord(char s[], int p[])
{
    p[0] = s[0] - 'a';
    p[1] = s[1] - '1';
}

int main()
{
    queue<int *> q;
    int a[8][8];
    int checked[8][8];
    int p1[2];
    int p2[2];
    int ps[8][8][2];
    char s1[100];
    char s2[100];
    int *po;

    int i;
    int j;

    int dx[8] = {-2, -2, -1, -1, +1, +1, +2, +2};
    int dy[8] = {-1, +1, -2, +2, -2, +2, -1, +1};

    for(i = 0; i < 8; i++)
    {
        for(j = 0; j < 8; j++)
        {
            ps[i][j][0] = i;
            ps[i][j][1] = j;
        }
    }

    while(scanf("%s%s", s1, s2) == 2)
    {
        getcord(s1, p1);
        getcord(s2, p2);

        for(i = 0; i < 8; i++)
        {
            for(j = 0; j < 8; j++)
            {
                a[i][j] = MAX;
                checked[i][j] = 0;
            }
        }

        q.push(p1);
        a[p1[0]][p1[1]] = 0;
        checked[p1[0]][p1[1]] = 0;
        while(q.size() != 0)
        {
            po = q.front();
            checked[po[0]][po[1]] = 1;
            for(i = 0; i < 8; i++)
            {
                if(inbound(po[0] + dx[i], po[1] + dy[i]))
                {
                    if(a[po[0] + dx[i]][po[1] + dy[i]] > a[po[0]][po[1]] + 1)
                    {
                        a[po[0] + dx[i]][po[1] + dy[i]] = a[po[0]][po[1]] + 1;
                    }

                    if(checked[po[0] + dx[i]][po[1] + dy[i]] == 0)
                    {
                        q.push(ps[po[0] + dx[i]][po[1] + dy[i]]);
                    }
                }
            }
            q.pop();
        }

        /*
        for(i = 0; i < 8; i++)
        {
            for(j = 0; j < 8; j++)
            {
                printf("%d ", a[i][j]);
            }
            printf("\n");
        }
        */
        printf("To get from %s to %s takes %d knight moves.\n", s1, s2, a[p2[0]][p2[1]]);
    }

    return 0;
}

