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
	//freopen("sets.in", "r", stdin);
#endif
}
//\/\/\/\/\/\/\/\/\/\/\/\/\/\//\/\/\/\//\/\/\/\/\/\/\/\/\/\/
int powerOf(int a, int b) {
	int ret = 1;
	long c = a;
	while (c < b) {
		c *= a;
		++ret;
	}
	return c == b ? ret : -1;
}

int main() {
	file(); //TODO
	while (true) {
		int H, W;
		scanf("%d%d", &H, &W);
		if (H + W == 0)
			break;

		int N = 2;
		if (W == 1)
			N = 1;
		else {
			while (true) {
				int x = powerOf(N, W), y = powerOf(N + 1, H);
				if (x != -1 && x == y)
					break;
				++N;
			}
		}

		int sumH = 0, c = 1, NW = 0;
		while (H > 0) {
			sumH += H * c;
			if (H > 1)
				NW += c;
			c *= N;
			H /= N + 1;
		}
		ot (NW), sp(), ot(sumH), ln();
		printf("%d %d\n", NW, sumH);
	}
	return 0;
}

