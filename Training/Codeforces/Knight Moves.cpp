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
/**************BASHAR*****************/
string s, m;
char arr[9][9];
int vis[9][9], x2, y2, cnt, cnt2;
int dx[] = { 1, -1, 2, -2, 1, -1, 2, -2 };
int dy[] = { 2, 2, 1, 1, -2, -2, -1, -1 };
int valid(int xx, int yy) {
	return xx >= 0 && xx < 8 && yy >= 0 && yy < 8;
}

queue<pair<pair<int, int>, int> > q;
void clearr() {
	while (q.size()) {
		q.pop();
	}
	cnt = 0;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			vis[i][j] = 0;
		}
	}

}
int bfs() {
	while (!q.empty()) {
		int i = q.front().fir.fir;
		int j = q.front().fir.sec;
		cnt = q.front().sec;
		q.pop();
		if (i == x2 && j == y2 - 1) {
			return cnt;
		}
		for (int z = 0; z < 8; z++) {
			int x = i + dx[z];
			int y = j + dy[z];
			if (valid(x, y) && !vis[x][y]) {
				q.push(make_pair(make_pair(x, y), cnt + 1));
			}
		}
	}
}
int main() {
	while (cin >> s >> m) {
		int x1 = s[0] - 97;
		int y1 = s[1] - '0';
		q.push(make_pair(make_pair(x1, y1 - 1), 0));
		x2 = m[0] - 97;
		y2 = m[1] - '0';
		int x = bfs();
		clearr();
		cout << "To get from " << s << " to " << m << " takes " << x
				<< " knight moves." << endl;
	}
}
