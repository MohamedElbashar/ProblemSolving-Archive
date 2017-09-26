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
int n, m;
map<ll, ll> mp;
map<ll, ll>::iterator it;
int main() {
	file();
	while (scanf("%d%d", &n, &m) && n && m) {fs
		int x;
		for (int i = 0; i < (n + m); i++) {
			scanf("%d", &x);
			mp[x]++;
		}
		x = 0;
		for (it = mp.begin(); it != mp.end(); it++) {
			if (it->second == 2) {
				x++;
			}
		}
		printf("%d\n", x);
		mp.clear();
	}
}
