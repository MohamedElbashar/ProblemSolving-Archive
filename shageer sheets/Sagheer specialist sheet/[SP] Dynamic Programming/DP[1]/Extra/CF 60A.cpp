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
#define maxx(a, b, c) max(max(a, b), c)and
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
int n, m, cnt;
bool arr[10001];
int main() {
	file();
	scanf("%d%d", &n, &m);
	mem(arr, 0);
	string s;
	getchar();

	while (m--) {
		int x = 0;
		getline(cin, s);
		if (s.find("left") != -1) {
			for (int i = 15; i <= sz(s); i++) {
				if (s[i] >= '0' && s[i] <= '9')
					x = x * 10 + (s[i] - '0');
			}
			for (int i = x; i <= n; i++) {
				arr[i] = true;
			}
		} else {
			for (int i = 15; i <= sz(s); i++) {
				if (s[i] >= '0' && s[i] <= '9')
					x = x * 10 + (s[i] - '0');
			}
			for (int i = x; i >= 1; i--) {
				arr[i] = true;
			}
		}
	}
	for (int i = 1; i <= n; i++)
		if (!arr[i])
			cnt++;
	printf("%d", cnt == 0 ? -1 : cnt);
}
