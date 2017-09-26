#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
#define PI 3.1415926535897932384626433832795
#define EPS  1e-10
#define ll long long
#define mem(a,b) memset(a,b,sizeof a)
#define oo 1e8
#define minn(a, b, c) min(min(a, b), c)
#define maxx(a, b, c) max(max(a, b), c)
int dx[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int di[] = { 1, -1, 0, 0 };
int dj[] = { 0, 0, 1, -1 };
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#else
	// online submission
	//freopen("interesting.in", "r", stdin);
#endif
}
//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\//\/\/\/\/\/\/\/\/\/
int main() {
	file();
	int g, money, k, TC, M, C;
	int price[25][25];
	bool reachable[25][210];
	scanf("%d", &TC);
	while (TC--) {
		scanf("%d %d", &M, &C);
		for (g = 0; g < C; g++) {
			scanf("%d", &price[g][0]);
			for (money = 1; money <= price[g][0]; money++)
				scanf("%d", &price[g][money]);
		}
		memset(reachable, false, sizeof reachable);
		for (g = 1; g <= price[0][0]; g++)
			if (M - price[0][g] >= 0)
				reachable[0][M - price[0][g]] = true;
		for (g = 1; g < C; g++)
			for (money = 0; money < M; money++)
				if (reachable[g - 1][money])
					for (k = 1; k <= price[g][0]; k++)
						if (money - price[g][k] >= 0)
							reachable[g][money - price[g][k]] = true;
		for (money = 0; money <= M && !reachable[C - 1][money]; money++)
			;
		if (money == M + 1)
			printf("no solution\n"); // last row has no on bit
		else
			printf("%d\n", M - money);
	}
}
