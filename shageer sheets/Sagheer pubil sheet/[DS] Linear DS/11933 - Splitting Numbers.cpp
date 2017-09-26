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
int n, a, b;
int main() {
	file();
	for (;;) {
		scanf("%d", &n);
		if (n == 0)
			break;

		int i = 0, j = 0; // index, number of ones
		a = 0, b = 0;
		while (n > 0) {
			if (1 & n) {
				if (j % 2) {
					b |= 1 << i;
				} else {
					a |= 1 << i;
				}
				j++;
			}
			i++;
			n = n >> 1;
		}

		printf("%d %d\n", a, b);
	}
}

