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
int n, x, vis[2001];
vi arr[2001];
int dfs(int cur) {
	vis[cur] = 1;
	int ret = 0;
	for (int i = 0; i < sz(arr[cur]); i++) {
		if (!vis[arr[cur][i]])
			ret = max(ret, dfs(arr[cur][i]) + 1);
	}
	return ret;
}
int main() {
	file();
	/*hena e4t8l 3ala el nas el -1 ele mlhm4 kber
	 * 3ml menhm tree b7es en kol wa7ed menhm byo2a3 fe group mo5tlf 3n el tane
	 * bgeb el depth bta3hm w ana nazel w ageb atwl wa7da
	 * */
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &x);
		if (x != -1)
			arr[x].push_back(i);
		else
			arr[0].push_back(i);
	}
	int ans = 0;
	for (int i = 0; i < sz(arr[0]); i++) {
		if (!vis[arr[0][i]]) {
			ans = max(ans, dfs(arr[0][i]));
		}
	}
	printf("%d", ans + 1);

}

