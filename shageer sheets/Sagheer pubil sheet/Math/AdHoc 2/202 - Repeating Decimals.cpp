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
#define maxx(a, b, c) max(max(a,	 b), c)
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
//\/\/\/\/\/\/\/\/\/\/\/\/\/\//\/\/\/\//\/\/\/\/\/\/\/\/\/\/
int main() {
	file();
	int n, m;
	int mark[3001], i, j;
	while (scanf("%d %d", &n, &m) == 2) {
		char s[3001], *str = s + 1;
		memset(mark, 0, sizeof(mark));
		printf("%d/%d = %d.", n, m, n / m);
		n %= m;
		mark[n] = 1;
		n *= 10;
		for (i = 2;; i++) {
			*str = n / m + '0', str++;
			if (mark[n % m])
				break;
			mark[n % m] = i;
			n %= m;
			n = n * 10;
		}
		int st = mark[n % m], ed = i;
		for (j = 1; j < ed && j <= 50; j++) {
			if (j == st)
				printf("(");
			printf("%c", s[j]);
		}
		if (j < ed)
			printf("...");
		printf(")\n");
		printf("   %d = number of digits in repeating cycle\n\n", ed - st);
	}
	return 0;
}
