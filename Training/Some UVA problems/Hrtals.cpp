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
//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\//\/\/\/\/\/\/\/\/\/
int t, n, p, cnt;
int arr[3651];
int main() {
	file();
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &p);
		int xx;
		while (p--) {
			scanf("%d", &xx);
			for (int i = xx; i <= n; i += xx) {
				if (arr[i] || i % 7 == 6 || i % 7 == 0)
					continue;
				else {
					arr[i] = 1;
					cnt++;
				}
			}
		}
		printf("%d\n", cnt);
		cnt = 0;
		mem(arr, 0);
	}
	return 0;

}

