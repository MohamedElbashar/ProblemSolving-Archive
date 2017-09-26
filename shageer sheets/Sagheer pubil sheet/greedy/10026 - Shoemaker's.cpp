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
	freopen("out.txt", "w", stdout);
#else
	// online submission
	//freopen("interesting.in", "r", stdin);
#endif
}
//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\//\/\/\/\/\/\/\/\/\/

//b3ml el job el ola w astana elfine bta3 el tanya w a4of bardo el3ks a3ml el tanya ....
int cmp(const pair<pair<int, int>, int> a, const pair<pair<int, int>, int> b) {
	return a.first.first * b.first.second < b.first.first * a.first.second;
}
int main() {
	file();
	int t, n, x, y;
	vector<pair<pair<int, int>, int>> v;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &x, &y);
			v.push_back(make_pair(make_pair(x, y), i + 1));
		}
		stable_sort(v.begin(), v.end(), cmp);
		printf("%d", v[0].second);
		for (int i = 1; i < n; i++) {
			printf(" %d", v[i].second);
		}
		printf("\n");
		if (t)
			printf("\n");
		v.clear();
	}
	return 0;
}
