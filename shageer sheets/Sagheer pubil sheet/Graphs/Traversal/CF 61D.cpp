#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
#define PI 3.1415926535897932384626433832795
#define ll long long
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define mem(a,b) memset(a,b,sizeof a)
#define oo 1e8
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
	//freopen("interesting.in", "r", stdin);
#endif
}
//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\//\/\/\/\/\/\/\/\/\/
int n, vis[100001], u, v, c;
ll sum;
vpi arr[100001];
ll dfs(int cur) {
	vis[cur] = 1;
	ll ret = 0;
	for (int i = 0; i < sz(arr[cur]); i++) {
		if (!vis[arr[cur][i].first]) {
			ret = max(ret, arr[cur][i].second + dfs(arr[cur][i].first));
		}
	}
	return ret;
}
int main() {
	/*hena 3wz a7esb el cost 7ata kaman fe el rg3a
	 * a3ml eh b2a ana ema bro7 w age 3ala tare2 yb2a el cost*2
	 * tayb ema ageb el cost bta3 el graph kolo fe el ra7a wl rag3a
	 * w a4of ana m4et 3ala el nodes ezay w atr7o men el all cost of graph
	 * haytl3le ele ana m4eto
	 * */
	file();
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		scanf("%d%d%d", &u, &v, &c);
		arr[u].pb( { v, c });
		arr[v].pb( { u, c });
		sum += (2 * c);
	}
	ll res = dfs(1);
	printf("%lld", sum - res);

}

