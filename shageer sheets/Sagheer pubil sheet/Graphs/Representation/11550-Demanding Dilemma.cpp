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
int n, m, t;
set<pair<int, int>> s;
int arr[10][30];
int main() {
	file();
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				scanf("%d", &arr[i][j]);
		bool flag = 1;
		for (int j = 0; j < m && flag; j++) {
			int sum = 0;
			int f = -1, sec = 0;
			for (int i = 0; i < n && flag; i++) {
				if (arr[i][j]) {
					sum++;
					if (f == -1)
						f = i;
					else
						sec = i;
				}
			}
			if (sum != 2)
				flag = 0;
			else if (s.find(make_pair(f, sec)) == s.end())
				s.insert(make_pair(f, sec));
			else
				flag = 0;
		}

		if (!flag)
			cout << "No\n";
		else
			cout << "Yes\n";
		s.clear();

	}

	return 0;
}
