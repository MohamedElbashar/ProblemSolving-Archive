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
int main() {
	file();
	int n;
	scanf("%d", &n);
	int arr[n];
	int res[n + 1] { 0 };
	for (int i = 0; i < n; scanf("%d", &arr[i]), i++)
		;
	sort(arr, arr + n);
	int c = 0;
	for (int i = 1; i <= n; i += 2) {
		res[i] = arr[c], c++;
	}
	for (int i = 2; i <= n; i += 2) {
		res[i] = arr[c], c++;
	}
	printf("%d", res[1]);
	for (int i = 2; i <= n; i++) {
		printf(" %d", res[i]);
	}
}
