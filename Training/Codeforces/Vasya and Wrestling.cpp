#include <bits/stdc++.h>
using namespace std;
typedef pair<int, string> pi;
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
int n, ls;
ll sum;
vi w1, w2;
int main() {
	file();
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		sum += x;
		if (x >= 0)
			w1.push_back(x);
		else
			w2.push_back(abs(x));

		if (i == n - 1)
			ls = x;
	}
	if (sum > 0) {
		printf("%s", "first");
		return 0;
	} else if (sum < 0) {
		printf("%s", "second");
		return 0;
	} else {
		for (int i = 0, j = 0; i < w1.size() && j < w2.size(); i++, j++) {
			if (w1[i] > w2[j]) {
				printf("first");
				return 0;
			}
			if (w1[i] < w2[j]) {
				printf("second");
				return 0;
			}
		}
		if (ls >= 0) {
			printf("%s", "first");
			return 0;
		} else {
			printf("%s", "second");
			return 0;
		}
	}

}
