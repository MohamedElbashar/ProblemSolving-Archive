#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
#define PI 3.1415926535897932384626433832795
#define ll long long
#define mem(a,b) memset(a,b,sizeof a)
#define oo 1e8
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
int n, q, t, x, cnt;
int arr[10001];
int main() {
	file();
	while (scanf("%d%d", &n, &q) && n && q) {
		for (int i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
		}
		stable_sort(arr, arr + n);
		printf("CASE# %d:\n", ++cnt);
		for (int i = 0; i < q; i++) {
			int idx;
			scanf("%d", &x);
			idx = lower_bound(arr, arr + n, x) - arr;
			if (arr[idx] == x)
				printf("%d found at %d\n", x, idx + 1);
			else
				printf("%d not found\n", x);
		}
	}
}
