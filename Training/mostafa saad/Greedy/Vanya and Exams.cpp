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
ll n, m, avg, ret, val;
ll sum, ans;
vpi v;
int cmp(pi a, pi b) {
	if (a.second == b.second)
		return a.first < b.first;
	else
		return a.second < b.second;

}
int main() {
	file();
	scanf("%d%d%d", &n, &m, &avg);
	for (int i = 0; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		v.push_back(make_pair(x, y));
		sum += x;
	}
	avg *= n;
	if (sum >= avg)
		return printf("%d", 0), 0;
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < n; i++) {
		val = avg - sum;
		if (v[i].first < m) {
			if (m - v[i].first < val) {
				sum += m - v[i].first;
				ans += ((m - v[i].first) * v[i].second);
			} else {
				sum += val;
				ans += (val * v[i].second);
			}
			if (sum == avg)
				break;
		}
	}
	if (ans < 0) {
		return printf("%d", 0), 0;
	}
	printf("%lld", ans);

}
