#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int N = 55;
int a, b, c, t;
int f[N][N][N];
int m[N][N][N];
int d[6][3] = {
	{-1, 0, 0}, 
	{+1, 0, 0}, 
	{0, -1, 0}, 
	{0, +1, 0}, 
	{0, 0, -1}, 
	{0, 0, +1}
};

bool inbound(int x, int y, int z)
{
	return (x >= 0 && x <= a - 1) 
			&& (y >= 0 && y <= b - 1) 
			&& (z >=0 && z <= c - 1);
}

int main()
{
	int caseno, ci;
	int i, j, k;
	queue<int> q;
	int p;
	int x, y, z;
	int x1, y1, z1;

	scanf("%d", &caseno);
	for (ci = 0; ci < caseno; ++ci) {
		scanf("%d%d%d%d", &a, &b, &c, &t);
		for (i = 0; i < a; ++i) {
			for (j = 0; j < b; ++j) {
				for (k = 0; k < c; ++k) {
					scanf("%d", &f[i][j][k]);
				}
			}
		}

		memset(m, 0, sizeof(m));
		m[0][0][0] = 1;
		q.push(0);
		while (!m[a - 1][b - 1][c - 1] && !q.empty()) {
			p = q.front();
			z = p % c;
			p /= c;
			y = p % b;
			p /= b;
			x = p % a;
			q.pop();

			for (i = 0; i < 6; ++i) {
				x1 = x + d[i][0];
				y1 = y + d[i][1];
				z1 = z + d[i][2];
				if (!inbound(x1, y1, z1)) {
					continue;
				}
				if (f[x1][y1][z1] || m[x1][y1][z1]) {
					continue;
				}
				m[x1][y1][z1] = m[x][y][z] + 1;
				q.push((x1 * b + y1) * c + z1);
			}
		}

		p = m[a - 1][b - 1][c - 1] - m[0][0][0];
		if (m[a - 1][b - 1][c - 1] == 0 || p > t) {
			printf("-1\n");
		} else {
			printf("%d\n", p);
		}

		while (!q.empty()) {
			q.pop();
		}
	}

	return 0;
}