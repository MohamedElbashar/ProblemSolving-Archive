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
#define sz(v) ((int)((v).size()))
#define minn(a, b, c) min(min(a, b), c)
#define maxx(a, b, c) max(max(a, b), c)and
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
int t, n, tot, x, arr[3651], cnt;
int main() {
	file();
	scanf("%d", &t);
	while (t--) {
		mem(arr, 0);
		scanf("%d%d", &tot, &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &x);
			for (int j = x; j <= tot; j += x) {
				arr[j]++;
			}
		}
		for (int i = 1; i <= tot; i++) {
			if ((i + 1) % 7 == 0 || i % 7 == 0)
				continue;
			else if (arr[i])
				cnt++;
		}
		printf("%d\n", cnt);
		cnt = 0;
	}

}
