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
int n, x, y, ret, mx, mn, cur, sum;
vi v, arr;
int main() {
	file();
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		v.push_back(x);
	}
	int j = 0;
	for (int i = 0; i < n; i++) {
		mx = v[i];
		mn = v[i];
		for (j = i + 1; j < n; j++) {
			mx = max(mx, v[j]);
			mn = min(mn, v[j]);
			if (mx - mn > 1)
				break;
		}
		ret = j - i;
		sum = max(sum, ret);
		if (sum == n - i)
			break;

	}
	cout << sum;
}
