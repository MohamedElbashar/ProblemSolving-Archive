#include<bits/stdc++.h>
using namespace std;

class node {
public:
	int ind, cost, wdom;
};
bool operator <(node a, node b) {
	if (a.cost != b.cost)
		return a.cost < b.cost;
	return a.ind < b.ind;
}
int n, m, en;
vector<int> arr[100001], c[100001], wis[100001];
set<node> S;
int dis[100001];
int dijkstra(int tes) {
	node cur;
	memset(dis, -1, sizeof dis);

	cur.ind = 1;
	cur.cost = 0;
	S.insert(cur);

	while (S.size()) {
		cur = *S.begin();
		S.erase(S.begin());

		if (dis[cur.ind] != -1)
			continue;
		dis[cur.ind] = cur.cost;
		if (cur.ind == en)
			return cur.cost;

		for (int i = 0; i < arr[cur.ind].size(); i++) {
			node temp;
			temp.ind = arr[cur.ind][i];
			temp.cost = cur.cost + c[cur.ind][i];
			temp.wdom = wis[cur.ind][i];

			if (dis[temp.ind] == -1 && wis[cur.ind][i] < tes)
				S.insert(temp);
		}
	}
	return -1;
}
int main() {
	int i, f, s, cost, wi;
	int test;
	int k;
	int mx = 0;
	while (test--) {
		cin >> n >> m >> k;
		for (i = 0; i < m; i++) {
			cin >> f >> s >> cost >> wi;
			if (mx < wi) {
				mx = wi;
			}
			arr[f].push_back(s);
			c[f].push_back(cost);
			wis[f].push_back(wi);

			arr[s].push_back(f);
			c[s].push_back(cost);
			wis[s].push_back(wi);
		}
		int srt = 1;
		int res;
		while (srt <= mx) {
			int mid = srt + mid / 2;
			if (dijkstra(mid) == -1) {
				srt = mid + 1;
			} else if (dijkstra(mid) < k) {
				res = mid;
				mx = mid - 1;
			} else if (dijkstra(mid) >= k) {
				srt = mid + 1;
			}
		}
		cout<<res;
	}
	return 0;
}

