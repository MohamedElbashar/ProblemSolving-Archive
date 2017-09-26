#include<bits/stdc++.h>
using namespace std;
vector<pair<int, int> > arr[50001];
int u, v, c, n, res, node, vis[50001], t;
void DFS(int cur, int sum) {
	if (res < sum) {
		res = sum;
		node = cur;
	}
	vis[cur] = 1;
	for (int i = 0; i < arr[cur].size(); i++) {
		if (!vis[arr[cur][i].first])
			DFS(arr[cur][i].first, sum + arr[cur][i].second);
	}
	vis[cur] = 0;
}
int main() {
	scanf("%d",&t);
	while (t--) {
		scanf("%d",&n);
		for (int i = 0; i < n - 1; i++) {
			scanf("%d %d %d",&u,&v,&c);
			arr[u].push_back(make_pair(v, c));
			arr[v].push_back(make_pair(u, c));
		}
		DFS(1, 0);
		res = 0;
		DFS(node, 0);
		printf("%d",res);
	}
}
