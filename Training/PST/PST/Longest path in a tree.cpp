#include <bits/stdc++.h>
using namespace std;
vector<int> arr[10001];
int u, v, n, vis[10001], res, node;
void dfs(int cur, int d) {
	if (res < d) {
		res=d;
		node = cur;
	}
	vis[cur] = 1;
	for (int i = 0; i < arr[cur].size(); i++) {
		if (!vis[arr[cur][i]])
			dfs(arr[cur][i], d + 1);
	}
	vis[cur] = 0;
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		scanf("%d %d", &u, &v);
		arr[u].push_back(v);
		arr[v].push_back(u);
	}
	dfs(1, 0);
	res = 0;
	dfs(node, 0);
	printf("%d", res);
}
