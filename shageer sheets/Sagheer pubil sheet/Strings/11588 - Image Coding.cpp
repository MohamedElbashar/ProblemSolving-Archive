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
	//freopen("sets.in", "r", stdin);
#endif
}
//\/\/\/\/\/\/\/\/\/\/\/\/\/\//\/\/\/\//\/\/\/\/\/\/\/\/\/\/
char f;
int r, c, n, m, k;
vi v;
int cnt[26];
int main() {
	file();
	int t;
	scanf("%d", &t);
	while (t--) {
		mem(cnt, 0);
		scanf("%d%d%d%d", &r, &c, &n, &m);
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				cin >> f;
				cnt[f - 'A']++;
			}
		}
		int mx = *max_element(cnt, cnt +26);
		int res = 0;
		for (int i = 0; i < 26; i++) {
			if (cnt[i] == mx)
				res += cnt[i] * n;
			else
				res += cnt[i] * m;
		}

		printf("Case %d: %d\n", ++k, res);
	}
}
