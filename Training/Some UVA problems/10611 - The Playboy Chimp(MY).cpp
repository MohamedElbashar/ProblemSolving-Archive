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
int n, q, arr[50001], x;
int main() {
	file();
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
		}
		scanf("%d", &q);
		for (int i = 0; i < q; i++) {
			scanf("%d", &x);
			if (x > arr[n - 1])
				printf("%d X\n", arr[n - 1]);
			else if (x < arr[0])
				printf("X %d\n", arr[0]);
			else if (x == arr[n - 1])
				printf("%d X\n", arr[(lower_bound(arr, arr + n, x) - arr) - 1]);
			else if (x == arr[0])
				printf("X %d\n", arr[(upper_bound(arr, arr + n, x) - arr)]);
			else {
				printf("%d %d\n", arr[(lower_bound(arr, arr + n, x) - arr) - 1],
						arr[(upper_bound(arr, arr + n, x) - arr)]);

			}

		}
	}
	return 0;
}
