#include <bits/stdc++.h>
using namespace std;
vector<int> arr[20001];
int vis[20001];
int cnt;
int n,m;
void dfs(int cur) {
	if (vis[cur]) {
		return ;
	}
	vis[cur] = 1;
	for (int i = 0; i < arr[cur].size(); i++) {
		dfs(arr[cur][i]);
	}
}
void connected() {
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			dfs(i);
			cnt++;
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		arr[u].push_back(v);
		arr[v].push_back(u);
	}

	if (m != n - 1) {
		cout << "NO";
		return 0;
	} else {
		connected();
		if (cnt == 1) {
			cout << "YES";
			return 0;
		} else {
			cout << "NO";
			return 0;
		}
	}
}
