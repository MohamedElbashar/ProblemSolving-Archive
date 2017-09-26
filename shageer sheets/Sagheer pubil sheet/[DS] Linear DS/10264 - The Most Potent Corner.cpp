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

inline bool neighbors(int i, int j) {
	int n = i ^ j;
	return (n & (-n)) == n;
}

int n, m, potencies[1 << 15];
int main() {
	while (cin >> n) {
		fill_n(potencies, 1 << n, 0);
		m = 0;
		for (int i = 0; i < (1 << n); i++) {
			int x;
			cin >> x;
			for (int j = 0; j < (1 << n); j++) {
				if (neighbors(i, j) && i != j)
					potencies[j] += x;
			}
		}
		// complete search for the maximum sum of potencies of two neighboring corners
		for (int i = 0; i < (1 << n); i++) {
			for (int j = 0; j < (1 << n); j++) {
				if (!neighbors(i, j) || i == j)
					continue;
				m = max(m, potencies[i] + potencies[j]);
			}
		}
		cout << m << '\n';
	}

	return 0;
}
