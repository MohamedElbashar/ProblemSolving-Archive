#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
#define PI 3.1415926535897932384626433832795
#define EPS  1e-10
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
int arr[100][100];
int main() {
	file();
	int n;
	while (scanf("%d", &n) != EOF) {
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) {
				scanf("%d", &arr[i][j]);
				arr[i][j] += arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
			}
		int mxsum = -oo, sub = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				for (int k = i; k <= n; k++)
					for (int l = j; l <= n; l++) {
						sub = arr[k][l];
						sub += arr[i - 1][j - 1]
								+ (-arr[i - 1][l] - arr[k][j - 1]);

						mxsum = max(sub, mxsum);
					}
		printf("%d\n", mxsum);
	}
}

