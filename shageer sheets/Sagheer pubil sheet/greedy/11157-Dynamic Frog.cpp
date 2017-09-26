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
int t, n, l, m, tt, res, pos[101], v[101], small[101];
int main() {
	file();
	scanf("%d", &t);
	while (t--) {
		char s, spa;
		scanf("%d%d", &n, &l);
		//getchar();
		for (int i = 0; i < n; i++) {
			cin >> s >> spa >> pos[i];
			small[i] = (s == 'S');
			v[i] = 0;
		}
		small[n] = 0, v[n] = 0, pos[n] = l;
		int mx = pos[0];
		for (int i = 0; i < n; i++) {
			v[i] = 1;
			if (!small[i + 1])
				mx = max(mx, pos[i + 1] - pos[i]);
			else
				mx = max(mx, pos[i + 2] - pos[i]), ++i;
		}

		for (int i = n; i > 0; --i)
			if (!v[i - 1] or !small[i - 1])
				mx = max(mx, pos[i] - pos[i - 1]);
			else
				mx = max(mx, pos[i] - pos[i - 2]), --i;
		printf("Case %d: %d\n", ++tt, mx);
	}
}
