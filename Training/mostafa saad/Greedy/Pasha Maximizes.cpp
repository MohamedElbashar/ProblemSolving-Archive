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
//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\//\/\/\/\/\/\/\/\/\/pi arr[1000001];
int n, flag;
int main() {
	file();
	string s;
	cin >> s >> n;
	for (int i = 0; i < s.length(); i++) {
		int idx = i;
		for (int j = i; j < s.length(); j++) {
			if (s[j] - '0' > s[idx] - '0' && j - i <= n) {
				idx = j;
			}
		}
		n -= (idx - i);
		for (int j = idx; j > i; j--) {
			swap(s[j], s[j - 1]);
		}
	}
	cout << s;
}
