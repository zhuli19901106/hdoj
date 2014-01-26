#include <cstdio>
#include <queue>
using namespace std;

int main()
{
	int n, i;
	int c, ci;
	priority_queue<int> pq;
	int tmp;

	while (scanf("%d", &c) == 1) {
		for (ci = 0; ci < c; ++ci) {
			scanf("%d", &n);
			for (i = 0; i < 2; ++i) {
				scanf("%d", &tmp);
				pq.push(tmp);
			}
			for (i = 2; i < n; ++i) {
				scanf("%d", &tmp);
				if (tmp < pq.top()) {
					pq.pop();
					pq.push(tmp);
				}
			}
			printf("%d\n", pq.top());
			while (!pq.empty()) {
				pq.pop();
			}
		}
	}

	return 0;
}