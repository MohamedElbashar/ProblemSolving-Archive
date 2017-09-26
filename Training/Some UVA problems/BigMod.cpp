#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
#define ll long long
#define mem(a,b) memset(a,b,sizeof a)
#define oo 1e8
#define minn(a, b, c) min(min(a, b), c)
#define maxx(a, b, c) max(max(a, b), c)
int dx[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int di[] = { 0, -1, 0, 1 };
int dj[] = { 0, 1, 1, 1 };
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
int BigMod(int b, int p, int m) {
	if (p == 0)
		return 1;
	if (p % 2 == 0) {
		int ret = BigMod(b, p / 2, m);
		return (ret * ret) % m;
	} else {
		int part1 = b % m;
		int part2 = BigMod(b, p - 1, m);
		return (part1 * part2) % m;
	}
}
int main() {
	file();
	int p, b, m;
	while (scanf("%d%d%d", &b, &p, &m)!=EOF)
		printf("%d\n", BigMod(b, p, m));

}
