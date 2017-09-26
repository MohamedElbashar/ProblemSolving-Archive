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

int main() {
	file();
	string s;

	cin >> s;
	ll sum = 0;
	ll cnt[26] { 0 }, cntn[10] { 0 };
	for (int i = 0; i < sz(s); i++) {
		if (isalpha(s[i])) {
			cnt[s[i] - 'a']++;
		} else if (isalnum(s[i]))
			cntn[s[i] - 48]++;
	}
	for (int i = 0; i < 26; i++) {
		if (cnt[i])
			sum += (cnt[i]) * (cnt[i]);
	}
	for (int i = 0; i < 10; i++) {
		if (cntn[i]) {
			sum += (cntn[i]) * (cntn[i]);
		}
	}

	printf("%lld", sum);
}
