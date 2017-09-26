#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pi> vpi;
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define mem(a,b) memset(a,b,sizeof a)
#define sz(v) ((int)((v).size()))
#define minn(a, b, c) min(min(a, b), c)
#define maxx(a, b, c) max(max(a, b), c)and
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
	//freopen("sets.in", "r", stdin);
#endif
}
//\/\/\/\/\/\/\/\/\/\/\/\/\/\//\/\/\/\//\/\/\/\/\/\/\/\/\/\/
string s;
int n, cnt[26];
string solve(int l) {
	string ret = "";
	for (int i = 0; i < 26; i++) {
		int cc = cnt[i] / l;
		if (cnt[i] % l)
			cc++;
		ret += string(cc, 'a' + i);
	}
	return ret;
}
int main() {
	file();

	cin >> s >> n;
	for (int i = 0; i < sz(s); i++) {
		cnt[s[i] - 'a']++;
	}
	int ans = 0;
	for (int i = 0; i < 26; i++)
		if (cnt[i])
			ans++;
	if (ans > n)
		return puts("-1"), 0;
	int res = 1;
	while (true) {
		string t = solve(res);
		if (sz(t) > n) {
			res++;
			continue;
		}
		while (sz(t) < n)
			t += "a";
		cout << res << endl;
		cout << t << endl;
		break;
	}

}
