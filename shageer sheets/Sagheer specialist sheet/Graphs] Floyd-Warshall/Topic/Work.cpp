#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<pi> vpi;
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define mem(a,b) memset(a,b,sizeof a)
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
//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\//\/\/\/\/\/\/\/\/\/\/

int main() {
	file();
	int t, m, n, u, v, c, ti, q;
	pi arr[50][50];
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				arr[i][j].first = INT_MAX, arr[i][j].second = INT_MAX;
				if (i == j)
					arr[i][j].first = 0, arr[i][j].second = 0;
			}
		}
		for (int i = 0; i < m; i++) {
			scanf("%d%d%d%d", &u, &v, &c, &ti);
			if (ti < arr[u][v].second)
				arr[u][v].first = c, arr[u][v].second = ti, arr[v][u].first = c, arr[v][u].second =
						ti;
			else if (ti == arr[u][v].second && c < arr[u][v].first) {
				arr[u][v].first = c, arr[v][u].first = c;
			}
		}
		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (arr[i][j].second > arr[i][k].second
							&& arr[k][j].second) {
						arr[i][j].second = arr[i][k].second + arr[k][j].second;
						arr[i][j].first = arr[i][k].first + arr[k][j].first;
					} else if (arr[i][j].second
							== arr[i][k].second + arr[k][j].second
							&& arr[i][j].first
									> arr[i][k].first + arr[k][j].first) {
						arr[i][j].first = arr[i][k].first + arr[k][j].first;
					}
				}
			}
		}
		scanf("%d", &q);
		for (int i = 0; i < q; i++) {
			scanf("%d%d", &u, &v);
			if (arr[u][v].first != INT_MAX) {
				printf("Distance and time to reach destination is %d & %d.\n",
						arr[u][v].first, arr[u][v].second);
			} else
				puts("No Path.");
		}
	}
	return 0;

}
