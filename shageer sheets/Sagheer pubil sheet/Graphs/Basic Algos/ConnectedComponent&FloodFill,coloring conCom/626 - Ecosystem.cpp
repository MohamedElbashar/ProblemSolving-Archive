#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
#define PI 3.1415926535897932384626433832795
#define ll long long
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define mem(a,b) memset(a,b,sizeof a)
#define oo 1e8
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
	//freopen("interesting.in", "r", stdin);
#endif
}
//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\//\/\/\/\/\/\/\/\/\/
int n, x, arr[101][101];
vector<pair<int, pi>> ans;
int main() {
	file();
	while (scanf("%d", &n) != EOF) {

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				scanf("%d", &arr[i][j]);
			}
		}
		int res = 0;
		for (int i = 1; i <= n; ++i)
			for (int j = i + 1; j <= n; ++j)
				if (arr[i][j])
					for (int k = i + 1; k <= n; ++k) {
						if (k != j && arr[j][k] && arr[k][i]) {
							if (j < k) {
								ans.push_back( { i, { j, k } });
							} else
								ans.push_back( { j, { k, i } });
							res++;
						}

					}
		sort(all(ans));
		for (auto it : ans)
			printf("%d %d %d\n", it.first, it.second.first, it.second.second);
		printf("total:%d\n\n", res);
		ans.clear();

	}

}

