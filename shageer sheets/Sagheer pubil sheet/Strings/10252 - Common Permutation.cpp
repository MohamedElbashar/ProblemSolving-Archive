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
	string s, s2, str;
	int cnt[26] { 0 }, cnt2[26] { 0 };
	getchar();
	while (getline(cin, s) && getline(cin, s2)) {
		mem(cnt, 0), mem(cnt2, 0);
		for (int i = 0; i < sz(s); i++)
			cnt[s[i] - 'a']++;

		for (int i = 0; i < sz(s2); i++)
			cnt2[s2[i] - 'a']++;
		for (int i = 0; i < 26; i++) {
			for (int j = 0; j < min(cnt[i], cnt2[i]); j++)
				str.push_back(i + 'a');
		}
		sort(str.begin(), str.end());
		cout << str << endl;
		str.clear();
	}
	return 0;
}
