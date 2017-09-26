#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pi> vpi;
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define mem(a,b) memset(a,b,sizeof a)
#define oo INT_MAX;
#define sz(v) ((int)((v).size()))
#define minn(a, b, c) min(min(a, b), c)
#define maxx(a, b, c) max(max(a, b), c)
int dx[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int di[] = { 1, -1, 0, 0 };
int dj[] = { 0, 0, 1, -1 };
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#else
	// online submission
	//freopen("sets.in", "r", stdin);
#endif
}
//\/\/\/\/\/\/\/\/\/\/\/\/\/\//\/\/\/\//\/\/\/\/\/\/\/\/\/\/
int n, cn, dis[11][11], path[11][11];
char arr[11][11];
int valid(int x, int y, int i) {
	return x >= 0 && x < n && y >= 0 && y < n
			&& (arr[x][y] == '.' || arr[x][y] - 'A' == i);
}
int main() {
	file();
	while (scanf("%d", &n) && n) {
		int x = -1, y = -1, no = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
				if (arr[i][j] == 'A') {
					x = i, y = j;
				}
				if (arr[i][j] >= 'A' && arr[i][j] <= 'Z') {
					no = max(no, arr[i][j] - 'A');
				}
			}
		}
		int cnt = 1, mn = 0;
		/*hena 3mlt loop 3ala el 7roof ele 3nde w kol mara b3ml BFS a4of h3raf awsal
		 * ll no2ta ele ana 3wzha wala la2
		 *  w kol mara b5zn el path bta3e wl b3ml array 3a4an a5zn feha el cost bta3e
		 *
	*/
		for (int i = 1; i <= no; i++) {
			mem(dis,0), mem(path, 0);
			dis[x][y] = path[x][y] = 1;
			queue<pi> q;
			q.push( { x, y });
			arr[x][y] = '.';
			x = -1, y = -1;
			while (!q.empty()) {
				pi cur = q.front();
				q.pop();
				if (arr[cur.first][cur.second] - 'A' == i)
					x = cur.first, y = cur.second;
				for (int j = 0; j < 4; j++) {
					int vx = cur.first + di[j];
					int vy = cur.second + dj[j];
					if (valid(vx, vy, i)) {
						if (!dis[vx][vy]) {
							dis[vx][vy] = dis[cur.first][cur.second] + 1;
							path[vx][vy] = path[cur.first][cur.second];
							q.push( { vx, vy });
						} else if (dis[vx][vy]
								== dis[cur.first][cur.second] + 1) {
							path[vx][vy] = (path[vx][vy]
									+ path[cur.first][cur.second]) % 20437;
						}

					}
				}
			}
			if (x == -1) {
				cnt = -1;
				break;
			}
			mn += dis[x][y] - 1;
			cnt = (cnt * path[x][y]) % 20437;
		}
		if (cnt == -1)
			printf("Case %d: Impossible\n", ++cn);
		else
			printf("Case %d: %d %d\n", ++cn, mn, cnt);
	}
}

