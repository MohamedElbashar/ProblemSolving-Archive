#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
#define ll long long
#define mem(a,b) memset(a,b,sizeof a)
#define oo 1e8
#define minn(a, b, c) min(min(a, b), c)
#define maxx(a, b, c) max(max(a, b), c)
int dx[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int di[] = { 0, -1, 0, 1 };
int dj[] = { 0, 1, 1, 1 };
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
int t, n, c;
int arr[100001];
int solve(int dis) {
	int cur = arr[0], cnt = 1;
	for (int i = 1; i < n; i++) {
		if (arr[i] - cur >= dis) {
			cnt++;
			cur = arr[i];
		}
	}
	if (cnt >= c)
		return 1;
	else
		return 0;
}
int main() {
	file();
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &c);
		for (int i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
		}
		sort(arr, arr + n);
		int low = 0, high = 1e9;
		while (low < high-1) {
			int mid = (low + high) / 2;
			if (solve(mid))
				low = mid;
			else
				high = mid;
		}
		if (solve(high))
			printf("%d\n", high);
		else
			printf("%d\n", low);
	}
}
