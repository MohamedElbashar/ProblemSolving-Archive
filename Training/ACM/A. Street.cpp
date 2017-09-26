#include<iostream>
#include <vector>
#include<set>
#include<string.h>
#include<algorithm>
using namespace std;
int dr[103], hei[103], wid[103], beg[103];
int n, l, w;
class node {
public:
	int ind, cost;
};

bool operator <(node a, node b) {
	if (a.cost != b.cost)
		return a.cost < b.cost;
	return a.ind < b.ind;
}
int n, m, st, en;
vector<int> arr[100001], c[100001];
set<node> S;
int dis[100001];
int dijkstra() {
	node cur;
	memset(dis, -1, sizeof dis);

	cur.ind = st;
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
			if (dis[temp.ind] == -1)
				S.insert(temp);
		}
	}
	return -1;
}
int main() {
	cin >> n >> l >> w;
	int a, b, k, d;
	for (int i = 0; i <= n; i++) {
		cin >> a >> b >> k >> d;
		hei[i] = a;
		wid[i] = b;
		beg[i] = k;
		dr[i] = d;
	}
	for(int i=1;i<=n;i++)
	{
		arr[0].push_back(i);
		arr[i].push_back(0);
		c[0].push_back(beg[i]);
		c[i].push_back(beg[i]);

	}
	for(int i=0;i<=n;i++)
		{
			arr[n+1].push_back(i);
			arr[i].push_back(n+1);
			c[n+1].push_back(hei[i]);
			c[i].push_back(hei[i]);
		}
	for (int i = 1; i <= n; i++) {
		for (int j = 2; j <= n; j++) {

			if (hei[i] >= beg[j]) {
				int p = w - wid[i] + wid[j];
				arr[i].push_back(j);
				c[i].push_back(p);


				arr[j].push_back(i);
				c[j].push_back(p);
			} else if (dir[i] == dir[j] && wid[i] >= wid[j]) {

				arr[i].push_back(j);
				c[i].push_back(beg[j] - hei[i]);

				arr[j].push_back(i);
				c[j].push_back(beg[j] - hei[i]);

			} else if (dir[i] == dir[j] && wid[i] <= wid[j]) {

				arr[i].push_back(j);
				c[i].push_back(beg[j] - hei[i]);

				arr[j].push_back(i);
				c[j].push_back(beg[j] - hei[i]);

			} else {

				double x = hypot(hei[i], beg[j]);
				arr[i].push_back(j);
				c[i].push_back(x);

				arr[j].push_back(i);
				c[j].push_back(x);

			}
		}
	}

}

