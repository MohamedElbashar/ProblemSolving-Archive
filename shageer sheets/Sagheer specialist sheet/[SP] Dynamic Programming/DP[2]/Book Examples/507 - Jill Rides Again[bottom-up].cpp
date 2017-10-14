#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
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
//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\//\/\/\/\/\/\/\/\/\/\/
int n, x, cnt;
int main() {
	file();
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		int sum = 0, ans = 0, nw=1, l , r;
		for (int i = 2; i <= n; i++) {
			scanf("%d", &x);
			sum += x;
			if (sum < 0)
				sum = 0, nw = i;
			if (sum >= ans) {
				if (sum > ans || (sum == ans && (i - nw > r - l))) {
					l = nw;
					r = i;
				}
				ans = sum;
			}
		}
		if (ans > 0)
			printf("The nicest part of route %d is between stops %d and %d\n",
					++cnt, l, r);
		else
			printf("Route %d has no nice parts\n", ++cnt);
	}
}
