#include <bits/stdc++.h>
using namespace std;
/**************BASHAR*****************/
struct node {
	int v, u, c;
	node(int v, int u, int c) :
			v(v), u(u), c(c) {
	}
	bool operator <(const node &e) const {
		return c > e.c;
	}
};
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
#define rep( i, n ) 	for (int i = 0; i < (n); i++)
#define scan(n) scanf("%d",&n)
#define mem(a,b) memset(a,b,sizeof(a))
#define ll long long
#define oo 1e9
int di[] = { 1, -1, 0, 0 };
int dj[] = { 0, 0, 1, -1 };
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//	freopen("out.txt", "w", stdout);
#else
	// online submission
	//freopen("interesting.in", "r", stdin);
#endif
}
/**************BASHAR*****************/
int n, m, a, b, cnt;
int arr[101];
queue<int> q;
vpi v;
int main() {
	file();
	scanf("%d%d", &n, &m);
	rep(i,m)
	{
		scanf("%d%d", &a, &b);
		arr[a]++;
		arr[b]++;
		v.push_back(make_pair(a, b));
	}
	int flag = 0, cut = 0;
	for (int j = 1; j < n; j++) {
		int flag = 0;
		for (int i = 0; i < v.size(); i++) {
			if (arr[v[i].first] == 1) {
				if (arr[v[i].second] > 1)
					q.push(v[i].second);
				if (arr[v[i].second] != 0) {
					arr[v[i].first]--;
					flag = 1;
				}
			}
			if (arr[v[i].second] == 1) {
				if (arr[v[i].first] > 1)
					q.push(v[i].first);
				if (arr[v[i].first] != 0) {
					arr[v[i].second]--;
					flag = 1;
				}
			}
			/*if (arr[v[i].first] == 0 && arr[v[i].second] == 0) {
				v.erase(v.begin() + i);
			}*/
		}
		if (flag) {
			cnt++;
		} else {
			break;
		}
		while (!q.empty()) {
			int x = q.front();
			q.pop();
			arr[x]--;
		}


	}
	cout << cnt;

}
