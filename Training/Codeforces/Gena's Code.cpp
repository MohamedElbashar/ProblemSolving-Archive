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
int n, z, o, cnt = 0;
int main() {
	file();
	cin >> n;
	string s, t = "1";
	ll pr = 1;
	for (int i = 0; i < n; i++) {
		cin >> s;
		if (s == "0" && s.size() == 1) {
			cout << 0;
			return 0;
		}
		z = 0;
		o = 0;
		for (int j = 0; j < int(s.length()); j++) {
			if (s[j] == '0')
				z++;
			else if (s[j] == '1')
				o++;
		}
		if (z + 1 != (int) s.size() || o != 1)
			t = s;
		else
			cnt += s.size() - 1;
	}
	string y(cnt, '0');
	cout << t << y;
}
