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
map<int, set<int>> mp;
int main() {
	file();
	int t, n, x, nw, cot;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &x);
			for (int j = 0; j < x; j++) {
				scanf("%d", &nw);
				mp[nw].insert(i + 1);
			}
		}
		int arr[n + 1];
		int cnt = 0;
		mem(arr, 0);
		for (int i = 1; i <= n; i++) {
			for (map<int, set<int>>::iterator it = mp.begin(); it != mp.end();
					it++) {
				if (it->second.size() == 1) {
					int xx = *it->second.begin();
					if (xx == i) {
						it->second.erase(it->second.begin());
						arr[xx]++;
						cnt++;
					}
				}
			}
		}
		printf("Case %d:", ++cot);
		if (cnt > 0) {
			for (int i = 1; i <= n; i++) {
				double percent = (double) arr[i] * 100.0 / (double) cnt;
				printf(" %.6lf%%", percent);
			}
		}
		printf("\n");
		mp.clear();
		cnt = 0;
	}
}
