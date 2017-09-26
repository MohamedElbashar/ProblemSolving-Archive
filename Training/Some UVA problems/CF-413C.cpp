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
struct ques {
	ll q, aUC;
} arr[101];
int n, m, x;
ll res;
bool cmp(ques c, ques d) {
	if (c.aUC != d.aUC)
		return c.aUC < d.aUC;
	return c.q > d.q;
}
int main() {
	file();
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i].q), arr[i].aUC = 0;
	for (int i = 0; i < m; i++)
		scanf("%d", &x), arr[x - 1].aUC = 1;
	sort(arr, arr + n, cmp);
	for (int i = 0; i < n; i++) {
		if (arr[i].aUC)
			res += max(res, arr[i].q);
		else
			res += arr[i].q;
	}
	printf("%I64d\n", res);

}
