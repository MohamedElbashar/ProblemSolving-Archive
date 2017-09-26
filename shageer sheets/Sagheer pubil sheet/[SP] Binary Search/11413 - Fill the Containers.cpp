#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
#define PI 3.1415926535897932384626433832795
#define EPS  1e-10
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
int n, m, arr[1001];
int can(int mid) {
	int cur = 0, cnt = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] > mid)
			return 0;
		if (arr[i] + cur > mid)
			cur = 0;
		if (cur == 0)
			cnt++;
		if (cnt > m)
			return false;
		cur += arr[i];
	}
	return true;
}
int main() {
	file();
	while (scanf("%d%d", &n, &m) != EOF) {
		ll sum = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
			sum += arr[i];
		}
		int st = 0, en = sum, mid, con = 0;
		while (st <= en) {
			mid = st + (en - st) / 2;
			if (can(mid)) {
				en = mid - 1, con = mid;
			} else
				st = mid + 1;
		}
		printf("%d\n", con);
	}

}
