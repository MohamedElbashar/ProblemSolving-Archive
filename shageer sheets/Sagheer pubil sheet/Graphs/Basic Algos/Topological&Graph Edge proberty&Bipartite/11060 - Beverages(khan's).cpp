#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
#define PI 3.1415926535897932384626433832795
#define ll long long
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define mem(a,b) memset(a,b,sizeof a)
#define oo 1e8
#define sz(v) ((int)((v).size()))
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
vi arr[101];
struct node {
	int nd;
	node(int nd) :
			nd(nd) {
	}
	bool operator <(const node &e) const {
		return nd > e.nd;
	}
};
vector<pair<string, int> > pr;
vi ans;
int n, m, val;
int cnt[101];
void solve() {
	priority_queue<node> q;
	for (int i = 0; i < n; i++) {
		if (cnt[i] == 0)
			q.push(i);
	}
	while (sz(q)) {
		node u = q.top();
		q.pop();
		ans.push_back(u.nd);
		for (int i = 0; i < sz(arr[u.nd]); i++) {
			if (--cnt[arr[u.nd][i]] == 0)
				q.push(arr[u.nd][i]);
		}
	}
}
void clr() {
	mem(cnt, 0), ans.clear(), pr.clear();
	for (int i = 0; i < n + 1; i++) {
		arr[i].clear();
	}
}
int main() {
	file();
	string s, t;
	while (scanf("%d", &n) != EOF) {
		map<string, int> cur;
		for (int i = 0; i < n; i++) {
			cin >> s;
			cur[s] = i;
			pr.push_back(mp(s, i));
		}
		scanf("%d", &m);
		for (int i = 0; i < m; i++) {
			cin >> s >> t;
			arr[cur[s]].push_back(cur[t]);
			cnt[cur[t]]++;
		}
		solve();
		printf("Case #%d: Dilbert should drink beverages in this order:",
				++val);
		for (int i = 0; i < sz(ans); i++) {
			cout << " " << pr[ans[i]].first;
		}
		printf(".\n\n");
		clr();
	}
}

