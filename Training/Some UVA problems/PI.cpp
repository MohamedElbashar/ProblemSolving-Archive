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
	freopen("out.txt", "w", stdout);
#else
	// online submission
	//freopen("interesting.in", "r", stdin);
#endif
}

//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\//\/\/\/\/\/\/\/\/\/
int n;
int main() {
	file();
	while (true) {
		scanf("%d", &n);
		if (n <= 1 || n >= 50)
			break;

		vi arr;
		arr.clear();
		int ret = n * (n - 1) / 2, cnt = 0;
		double ans = 0.0;
		for (int i = 0; i < n; i++) {
			int x;
			scanf("%d", &x);
			arr.push_back(x);
		}
		for (int i = 0; i < arr.size(); i++) {
			for (int j = i + 1; j < arr.size(); j++) {
				if (i == j)
					continue;
				int xx = __gcd(arr[i], arr[j]);
				if (xx == 1) {
					cnt++;
				}
			}
		}
		if (cnt == 0) {
			printf("%s\n", "No estimate for this data set.");
			continue;
		}
		ans = (double) cnt / ret;
		double res = (double) 6 / ans;
		double anss = (double) sqrt(res);
		cout << fixed << setprecision(6) << anss << endl;
	}
}
