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
	int cnts[26] { 0 }, cntc[26] { 0 };
	getline(cin, s);
	for (int i = 0; i < (int) s.length(); i++) {
		if (isalpha(s[i])) {
			if (islower(s[i]))
				cnts[s[i] - 'a']++;
			else
				cntc[s[i] - 'A']++;
		}
	}
	getline(cin, str);
	for (int i = 0; i < (int) str.length(); i++) {
		if (isalpha(str[i])) {
			if (islower(str[i])) {
				if (cnts[str[i] - 'a'] > 0) {
					cnts[str[i] - 'a']--;

				} else if (cnts[str[i] - 'a'] == 0)
					return puts("NO"), 0;
			} else {
				if (cntc[str[i] - 'A'] > 0)
					cntc[str[i] - 'A']--;
				else if (cntc[str[i] - 'A'] == 0)
					return puts("NO"), 0;
			}
		}
	}
	return puts("YES"), 0;
}
