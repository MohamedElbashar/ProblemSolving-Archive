#include <bits/stdc++.h>
using namespace std;
/**************BASHAR*****************/
struct node {
	int u, v, c;
	node(int u, int v, int c) :
			u(u), v(v), c(c) {
	}
	bool operator <(const node &e) const {
		return c > e.c;
	}
};
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
#define rep( i, n ) for (int i = 0; i < (n); i++)
#define scan(n) scanf("%d",&n)
#define scanl(n) scanf("%I64d",&n)
#define mem(a,b) memset(a,b,sizeof(a))
#define ll long long
#define oo 1e15
#define minn(a, b, c) min(min(a, b), c)
#define maxx(a, b, c) max(max(a, b), c)
int di[] = { 0, -1, 0, 1 };
int dj[] = { 0, 1, 1, 1 };
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#else
	// online submission
	//freopen("interesting.in", "r", stdin);
#endif
}
/**************BASHAR*****************/
int n, p, k;

int cnt[1001];
int arr[1001];
int dfs(int u, vector<int> * v) {
	if (arr[u])
		return 0;
	arr[u] = true;
	int ans = 1;
	vector<int> & vec = v[u];
	for (int i = 0; i < vec.size(); ++i) {
		if (!arr[vec[i]]) {
			ans += dfs(vec[i], v);
		}
	}
	return ans;
}

int main() {
	file();
	while (cin >> n && n) {
		scanf("%d%d", &p, &k);
		vector<int> vv[1001];
		for (int i = 0; i < p; i++) {
			int u, v;

			scanf("%d%d", &u, &v);
			u--, v--;
			vv[u].push_back(v);
			vv[v].push_back(u);
			cnt[v]++;
			cnt[u]++;
		}
		int xx = 1;
		while (xx) {
			xx = false;
			for (int i = 0; i < n; ++i) {
				if (cnt[i] < k && !arr[i]) {
					arr[i] = true;
					vi &vec = vv[i];
					for (int j = 0; j < vec.size(); ++j) {
						cnt[vec[j]]--;
					}
					xx = true;
				}
			}
		}
		int res = 0;
		for (int i = 0; i < n; ++i) {
			if (!arr[i]) {
				int ans = dfs(i, vv);
				if (ans > res)
					res = ans;
			}
		}
		printf("%d\n", res);
	}

}
