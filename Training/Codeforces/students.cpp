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
int t, n;
int main() {
	scanf("%d", &t);
	while (t--) {
		int arr[9][9] = { 0 };
		vi v;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			v.push_back(i);
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				scanf("%d", &arr[i][j]);
			}
		}
		int mn = INT_MAX;
		do {
			int ans = 0;
			for (int i = v.size() - 1; i > 0; i--) {
				int xx = v[i], yy = v[i - 1];
				if (!arr[xx][yy])
					ans++;
			}
			mn = min(ans, mn);
		} while (next_permutation(v.begin(), v.end()));
		printf("%d\n", mn);
	}
}
