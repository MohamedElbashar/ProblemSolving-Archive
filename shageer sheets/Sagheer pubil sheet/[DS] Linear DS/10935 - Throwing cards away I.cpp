#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
#define PI 3.1415926535897932384626433832795
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
int n, x, y;
vector<int> v;
queue<int> q;
int main() {
	file();
	while (scanf("%d", &n) && n) {

		for (int i = 1; i <= n; i++) {
			q.push(i);
		}
		while (q.size() > 1) {
			y = q.front();
			q.pop();
			v.push_back(y);
			x = q.front();
			q.push(x);
			q.pop();
		}
		printf("Discarded cards:");
		if (n > 1) {
			printf(" %d", v[0]);
		}
		for (int i = 1; i < v.size(); i++) {
			printf(", %d", v[i]);
		}
		printf("\nRemaining card: %d\n", q.front());
		q.pop();
		v.clear();
	}
}

