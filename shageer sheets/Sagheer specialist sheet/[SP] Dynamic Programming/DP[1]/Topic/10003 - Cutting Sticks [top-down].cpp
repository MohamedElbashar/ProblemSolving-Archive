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
int l, n, arr[52], memo[52][52];
int cut(int begin, int end, int left, int right) {
	if (begin >= end || left > right)
		return 0;
	int &ret = memo[left][right];
	if (ret != -1)
		return ret;
	int tot = 1e9;
	for (int i = left; i <= right; i++) {
		int cur = end - begin;
		int path1 = cut(begin, arr[i], left, i - 1);
		int path2 = cut(arr[i], end, i + 1, right);
		cur += path1 + path2;
		tot = min(tot, cur);
	}
	if (tot == 1e9)
		tot = 0;
	return ret = tot;
}
int main() {
	file();
	while (scanf("%d", &l) && l) {
		scanf("%d", &n);
		mem(memo, -1);
		for (int i = 0; i < n; i++)
			scanf("%d", &arr[i]);
		printf("The minimum cutting is %d.\n", cut(0, l, 0, n - 1));
	}
}

