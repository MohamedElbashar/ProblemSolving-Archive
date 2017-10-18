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
int t, n, m, num, dist[11][11], memo[11][1 << 11];
pi arr[11];
int tsp(int pos, int bitmask) {
	if (bitmask == (1 << (num + 1)) - 1)
		return dist[pos][0];
	int &ret = memo[pos][bitmask];
	if (ret != -1)
		return memo[pos][bitmask];
	int ans = 1e9;
	for (int i = 0; i <= num; i++) {
		if (i != pos && !(bitmask & (1 << i))) {
			ans = min(ans, tsp(i, bitmask | (1 << i)) + dist[pos][i]);
		}
	}
	return ret = ans;
}
int main() {
	file();
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d%d%d", &n, &m, &arr[0].first, &arr[0].second, &num);
		for (int i = 1; i <= num; i++)
			scanf("%d%d", &arr[i].first, &arr[i].second);
		for (int i = 0; i <= num; i++) {
			for (int j = 0; j <= num; j++) {
				dist[i][j] = abs(arr[i].first - arr[j].first)
						+ abs(arr[i].second - arr[j].second);
			}
		}
		mem(memo, -1);
		printf("The shortest path has length %d\n", tsp(0, 1));
	}
}
