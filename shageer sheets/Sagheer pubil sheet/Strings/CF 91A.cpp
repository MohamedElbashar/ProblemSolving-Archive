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
	string s, str;
	int cnts[26] { 0 }, cntstr[26] { 0 }, res;
	vi arr[26];
	cin >> s >> str;
	for (int i = 0; i < sz(s); i++)
		cnts[s[i] - 'a'] = 1, arr[s[i] - 'a'].pb(i);
	for (int i = 0; i < sz(str); i++)
		cntstr[str[i] - 'a'] = 1;
	for (int i = 0; i < 26; i++) {
		if (cnts[i] != cntstr[i] && cntstr[i])
			return puts("-1"), 0;
	}
	int sum = 1, idx = -1;
	for (int i = 0; i < sz(str); i++) {
		auto it = upper_bound(arr[str[i] - 'a'].begin(),
				arr[str[i] - 'a'].end(), idx);
		if (it == arr[str[i] - 'a'].end()) {
			sum++;
			idx = arr[str[i] - 'a'][0];
		} else
			idx = *it;
	}
	printf("%d", sum);

}
