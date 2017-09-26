#include <bits/stdc++.h>
using namespace std;
vector<int> arr[100];
int n, m,cnt;
int vis[100];
void DFS(int cur) {
	if (vis[cur])
		return;
	cnt++;
	vis[cur] = 1;
	for (int i = 0; i < arr[cur].size(); i++) {
		DFS(arr[cur][i]);
	}
}
int main() {
	cin >> n>>m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		arr[u].push_back(v);
		arr[v].push_back(u);
	}
	DFS(1);
	cout << cnt;
}
