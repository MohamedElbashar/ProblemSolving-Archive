#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
#define PI 3.1415926535897932384626433832795
#define ll long long
#define all(v) v.begin(),v.end()
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
int m, s, res;
vi v;
int solve(int m, int s) {
	return s >= 0 && s <= 9 * m;
}
int main() {
	file();
	scanf("%d%d", &m, &s);
	res = s;
	string ans;
	if (s == 0) {
		if (m == 1)
			cout << 0 << " " << 0;
		if (m > 1)
			cout << -1 << " " << -1;
		return 0;
	} else if (m * 9 < s) {
		cout << -1 << " " << -1;
		return 0;
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < 10; j++) {
			if ((i > 0 || j > 0 || (m == 1 && j == 0))
					&& solve(m - i - 1, res - j)) {
				char x = j + '0';
				ans += x;
				res -= j;
				break;
			}
		}
	}
	if (ans[0] == '0' || res) {
		printf("%d %d", -1, -1);
	} else {
		string temp;
		res = s;
		for (int i = 0; i < m; i++) {
			for (int j = 9; j >= 0; j--) {
				if (solve(m - i - 1, res - j)) {
					char x = j + '0';
					temp += x;
					res -= j;
					break;
				}
			}
		}
		cout << ans << " " << temp;

	}
}
