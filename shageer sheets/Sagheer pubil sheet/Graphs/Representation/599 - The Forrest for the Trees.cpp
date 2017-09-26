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
int t, vis[101], viss[101];
vpi arr;
vi node, vc, diff;
ll ct;
void clr() {
	node.clear(), vc.clear(), diff.clear(), arr.clear();
}
int main() {
	file();
	scanf("%d", &t);
	string str, s;
	while (t--) {
		int cnt = 0;
		mem(vis, 0), mem(viss, 0);
		cin >> s;
		if (s[0] != '*') {
			cnt++;
			arr.push_back( { (int) s[1], (int) s[3] });
			viss[(int) s[1]] = 1, viss[(int) s[3]] = 1;
			vis[(int) s[1]] = 1, vis[(int) s[3]] = 1;
			node.push_back((int) s[1]), node.push_back((int) s[3]);
			while (cin >> s && s[0] != '*') {
				arr.push_back( { (int) s[1], (int) s[3] });
				if (!viss[(int) s[1]] && !viss[(int) s[3]])
					cnt++;
				viss[(int) s[1]] = 1, viss[(int) s[3]] = 1;
				if (!vis[(int) s[1]])
					node.push_back((int) s[1]), vis[(int) s[1]] = 1;
				if (!vis[(int) s[3]])
					node.push_back((int) s[3]), vis[(int) s[3]] = 1;
			}
		} else {
			cin >> str;
			for (int i = 0; i < (int) str.length(); i += 2) {
				vc.push_back((int) str[i]);
			}
		}
		sort(node.begin(), node.end());
		sort(vc.begin(), vc.end());
		set_difference(vc.begin(), vc.end(), node.begin(), node.end(),
				inserter(diff, diff.begin()));
		printf("There are %d tree(s) and %d acorn(s).\n", cnt,
				(int) diff.size());
		clr();
	}
	return 0;
}

