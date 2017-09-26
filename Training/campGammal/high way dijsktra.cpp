#include <bits/stdc++.h>
using namespace std;
struct node {
	int ind, cost;
};
set<node> s;
int n, m, st, en;
vector<int> arr[100000], c[100000];
int dis[100001];
bool operator <(node a, node b) {
	if (a.cost != b.cost)
		return a.cost < b.cost;
	return a.ind < b.ind;
}

int dijkstra() {
	node cur;
	memset(dis, -1, sizeof dis);
	cur.ind = st;
	cur.cost = 0;
	s.insert(cur);
	while (s.size()) {
		cur = *s.begin();
		s.erase(s.begin());
		if (dis[cur.ind] != -1)
			continue;
		dis[cur.ind] = cur.cost;
		if (cur.ind == en)
			return cur.cost;
		for (int i = 0; i < arr[cur.ind].size(); i++) {
			node temp;
			temp.ind = arr[cur.ind][i];
			temp.cost = cur.cost + c[cur.ind][i];
			if (dis[temp.ind] == -1)
				s.insert(temp);
		}
	}
	return -1;
}
int main() {
	int i, j, s, f, cost;
	cin >> n >> m >> st >> en;
	for (i = 0; i < m; i++) {
		cin >> s >> f >> cost;
		arr[f].push_back(s);
		c[f].push_back(cost);

		arr[s].push_back(f);
		c[s].push_back(cost);
	}
	cout << dijkstra();
	cout << endl;

}

