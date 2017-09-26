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
	map<int, int> mp;
	char s[10001];
	int cur, mn;
	scanf("%d", &t);
	while (t--) {
		mp.clear();
		scanf("%d", &n);
		getchar();
		mn = oo;
		for (int i = 1; i <= n; i++) {
			gets(s);
			cur = 1;
			for (int j = 0; s[j] != '\0'; j++) {
				if (s[j] == ' ')
					cur++;
			}
			mp[i] = cur;
			if (cur < mn)
				mn = cur;
		}
		int f = 1;
		for (int i = 1; i <= n; i++) {
			if (mp[i] == mn) {
				if (!f)
					printf(" ");
				printf("%d", i);
				f = 0;
			}
		}
		printf("\n");
	}
}

