#include <bits/stdc++.h>
using namespace std;
int n, m, vis[101], ret;
double answer[101];
vector<double> v;
vector<pair<int, double> > arr[5000];
struct node {
	int x;
	double cost;
	node(int x, double cost) :
			x(x), cost(cost) {
	}
	bool operator <(const node &e) const {
		return cost < e.cost;
	}
};
priority_queue<node> q;
void clear() {
	while (q.size()) {
		q.pop();
	}
}

int main() {
	while (cin >> n && n) {
		cin >> m;
		for (int i = 0; i < m; i++) {
			int u, v;
			double c;
			cin >> u >> v >> c;
			arr[u].push_back(make_pair(v, c / 100));
			arr[v].push_back(make_pair(u, c / 100));
		}
		q.push(node(n, 1));
		double sum=1;
		while (q.size()) {
			int cur = q.top().x;
			double c = q.top().cost;
			q.pop();
			if (vis[cur])
				continue;
			vis[cur] = 1;
			if (cur == 1) {
				cout<<fixed<<setprecision(6)<<c*100<<" percent"<<endl;
				break;
			}
			for(int i=0;i<arr[cur].size();i++){
				if(vis[arr[cur][i].first])
					continue;
				q.push(node(arr[cur][i].first,arr[cur][i].second*c));
			}
		}
	}
}
