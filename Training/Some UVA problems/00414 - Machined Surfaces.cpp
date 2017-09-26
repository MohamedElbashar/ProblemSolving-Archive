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
int n, flag;
vi v;
int main() {
	file();
	while (cin >> n && n) {
		string arr;
		getchar();
		for (int i = 0; i < n; i++) {
			getline(cin, arr);
			int cnt = 0;
			for (int i = 0; i < arr.length(); i++) {
				if (arr[i] != 'X')
					cnt++;
			}
			v.push_back(cnt);
		}
		sort(v.begin(), v.end());
		int ans = v[0];
		int ret = 0;
		for (int i = 1; i < v.size(); i++) {
			ret += v[i] - ans;
		}
		printf("%d\n", ret);
		v.clear();
	}
	return 0;
}

