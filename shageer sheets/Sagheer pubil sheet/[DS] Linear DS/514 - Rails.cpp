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
int n;
int a[1001];

int main() {
	file();
	while (scanf("%d", &n) && n) {
		while (true) {
			scanf("%d", &a[0]);
			if (!a[0]) {
				printf("\n");
				break;
			}
			for (int i = 1; i < n; i++) {
				scanf("%d", &a[i]);
			}
			stack<int> st;
			int cur = 1, x = 0;
			while (cur <= n) {
				st.push(cur);
				while (st.size() && st.top() == a[x]) {
					st.pop();
					x++;
					if (x >= n)
						break;
				}
				cur++;
			}
			if (st.empty())
				printf("Yes\n");
			else
				printf("No\n");

		}
	}

}

