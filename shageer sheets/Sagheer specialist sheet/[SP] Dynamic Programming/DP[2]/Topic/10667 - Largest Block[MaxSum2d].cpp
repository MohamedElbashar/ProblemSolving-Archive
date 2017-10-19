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
int n, q, arr[101][101], r1, r2, c1, c2;
int main() {
	file();
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &q);
		mem(arr, 0);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				arr[i][j]++;
			}
		}
		for (int i = 0; i < q; i++) {
			scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
			r1--;
			c1--;
			for (int j = r1; j < r2; j++) {
				for (int k = c1; k < c2; k++) {
					arr[j][k] = -1e5;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i > 0) {
					arr[i][j] += arr[i - 1][j];
				}
				if (j > 0) {
					arr[i][j] += arr[i][j - 1];
				}
				if (i > 0 && j > 0) {
					arr[i][j] -= arr[i - 1][j - 1];
				}
			}
		}
		int ans = -1e5;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = i; k < n; k++) {
					for (int l = j; l < n; l++) {
						int mx = arr[k][l];
						if (i > 0)
							mx -= arr[i - 1][l];
						if (j > 0)
							mx -= arr[k][j - 1];
						if (i > 0 && j > 0)
							mx += arr[i - 1][j - 1];
						ans = max(mx, ans);

					}
				}
			}
		}
		ans = max(ans, 0);
		printf("%d\n", ans);

	}

}
