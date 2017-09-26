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
using namespace std;
int main() {
	file();
	int n, a;
	while (scanf("%d", &n)) {
		if (n == 0)
			break;
		priority_queue<int> pq;
		int sum = 0, i, c = 0;
		for (i = 0; i < n; i++) {
			scanf("%d", &a);
			pq.push(-a);
		}
		for (i = 0; i < n - 1; i++) {
			int d = -pq.top();
			pq.pop();
			int b = -pq.top();
			pq.pop();
			c = d + b;
			sum += c;
			pq.push(-c);
		}
		printf("%d\n", sum);
	}

	return 0;
}
