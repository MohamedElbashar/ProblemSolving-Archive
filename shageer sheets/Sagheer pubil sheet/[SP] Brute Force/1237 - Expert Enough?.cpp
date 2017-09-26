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
int t, q, n, x;

int main() {
	file();
	vector<pair<string, pair<int, int> > > mp;
	scanf("%d", &t);
	int cur = 0;
	while (t--) {
		if (cur)
			printf("\n");
		scanf("%d", &n);
		string s;
		int u, v;
		for (int i = 0; i < n; i++) {
			cin >> s >> u >> v;
			mp.push_back(make_pair(s, make_pair(u, v)));
		}
		scanf("%d", &q);
		for (int i = 0; i < q; i++) {
			int cnt = 0;
			string str;
			scanf("%d", &x);
			for (vector<pair<string, pair<int, int> > >::iterator it =
					mp.begin(); it != mp.end(); it++) {
				if (it->second.first <= x && it->second.second >= x) {
					str = it->first;
					cnt++;
				}
			}
			if (cnt > 1 || cnt == 0)
				printf("UNDETERMINED\n");
			else
				cout << str << "\n";
		}
		cur++;
		mp.clear();
	}
	return 0;
}

