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
int t, n;
int main() {
	file();

	char s[10001];
	int cur, mn;
	scanf("%d", &t);
	while (t--) {
		vi arr[1001];
		scanf("%d", &n);
		getchar();
		mn = oo;
		for (int i = 1; i <= n; i++) {
			gets(s);
			cur = 1;
			string str;
			int val;
			istringstream iss(s);
			while (iss >> val) {
				arr[i].push_back(val);
			}
			if ((int) arr[i].size() < mn)
				mn = (int) arr[i].size();
		}
		int f = 0;
		for (int i = 1; i <= n; i++) {

			if ((int) arr[i].size() == mn) {
				if (f)
					printf(" ");
				printf("%d", i), f = 1;
			}

		}
		printf("\n");
	}
	return 0;
}

