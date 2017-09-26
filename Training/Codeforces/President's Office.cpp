#include <bits/stdc++.h>
using namespace std;
/**************BASHAR*****************/
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
#define mem(a,b) memset(a,b,sizeof(a))
#define ll long long
#define oo 1e9
#define fir first
#define sec second
int di[] = { 1, -1, 0, 0 };
int dj[] = { 0, 0, 1, -1 };
//I64d
/**************BASHAR*****************/
int n, m;
char c, arr[101][101];
queue<pair<int, int> > q;
int vis[101][101];
int x, y, cnt, ans;
set<char>vec;
int valid(int i, int j) {
	return i < n && i >= 0 && j < m && j >= 0 && arr[i][j] != '.'&&arr[i][j]!=c
			;
}
int bfs() {
	while (!q.empty()) {
		x = q.front().fir;
		y = q.front().sec;
		q.pop();
		cnt = 0;
		for (int z = 0; z < 4; z++) {
			int i = x + di[z];
			int j = y + dj[z];
			if (valid(i, j) && !vis[i][j]) {
				vec.insert(arr[i][j]);
			}
		}
	}
	return vec.size();
}
int main() {
	scanf("%d%d", &n, &m);
	cin >> c;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == c) {
				q.push(make_pair(i, j));
			}
		}
	}
	int xx = bfs();
	printf("%d", xx);
}
