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
int b[3], g[3], c[3];
string s[] = { "BGC", "BCG", "GBC", "GCB", "CBG", "CGB" };
string str;
int s_b, s_g, s_c, cnt;
ll sum, ans;
int main() {
	file();
	while (scanf("%d%d%d%d%d%d%d%d%d", &b[0], &b[1], &b[2], &g[0], &g[1], &g[2],
			&c[0], &c[1], &c[2]) == 9) {

		int arr[] = { 0, 1, 2 };
		cnt = 0;
		ans = (1LL << 31);
		s_b = b[0] + b[1] + b[2];
		s_c = c[0] + c[1] + c[2];
		s_g = g[0] + g[1] + g[2];
		do {
			sum = s_b - b[arr[0]] + s_g - g[arr[1]] + s_c - c[arr[2]];
			if (sum < ans || (sum == ans && s[cnt] < str)) {
				str = s[cnt];
				ans = sum;
			}
			cnt++;
		} while (next_permutation(arr, arr + 3));
		cout << str << " " << ans << "\n";

	}
	return 0;
}

