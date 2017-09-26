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
int res[20], cnt, arr[20], n;
int isprime(int k) {
	for (int i = 2; i * i <= k; i++) {
		if (k % i == 0)
			return 0;
	}
	return 1;
}
void backtrack(int N) {
	if (N == n - 1 && isprime(res[n - 1] + res[0])) {
		for (int i = 0; i < n; i++)
			printf(i == n - 1 ? "%d" : "%d ", res[i]);
		printf("\n");
		return;
	}
	for (int i = 2; i <= n; i++) {
		if (!arr[i] && isprime(i + res[N])) {
			arr[i] = 1;
			res[N + 1] = i;
			backtrack(N + 1);
			arr[i] = 0;
		}
	}
}
int main() {
	file();
	while (scanf("%d", &n) != EOF) {
		res[0] = res[1] = 1;
		cnt++;
		if (cnt > 1)
			printf("\n");
		memset(arr, 0, sizeof(arr));
		printf("Case %d:\n", cnt);
		backtrack(0);
	}
	return 0;
}

