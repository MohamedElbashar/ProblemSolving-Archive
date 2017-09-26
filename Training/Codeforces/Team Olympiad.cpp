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
int n, m, x;
int main() {
	file();
	scanf("%d", &n);
	vi v1, v2, v3;
	vector<pair<pair<int, int>, int> > ans;
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		if (x == 1)
			v1.push_back(i + 1);
		else if (x == 2)
			v2.push_back(i + 1);
		else if (x == 3)
			v3.push_back(i + 1);
	}
	int i = 0, xx = v1.size(), y = v2.size(), z = v3.size(), flag = 0;
	while (xx-- && y-- && z--) {
		ans.push_back(make_pair(make_pair(v1[i], v2[i]), v3[i]));
		i++;
		flag = 1;
	}

	if (!flag) {
		printf("%d", 0);
		return 0;
	} else {
		printf("%d\n", ans.size());
		for (int i = 0; i < ans.size(); i++) {
			printf("%d %d %d\n", ans[i].first.first, ans[i].first.second,
					ans[i].second);
		}
		return 0;
	}

}

