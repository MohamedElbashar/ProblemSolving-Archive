#include <bits/stdc++.h>
using namespace std;
/**************BASHAR*****************/
struct node {
	int u, v, c;
	node(int u, int v, int c) :
			u(u), v(v), c(c) {
	}
	bool operator <(const node &e) const {
		return c > e.c;
	}
};
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
#define rep( i, n ) for (int i = 0; i < (n); i++)
#define scan(n) scanf("%d",&n)
#define scanl(n) scanf("%I64d",&n)
#define mem(a,b) memset(a,b,sizeof(a))
#define ll long long
#define oo 1e9
#define minn(a, b, c) min(min(a, b), c)
#define maxx(a, b, c) max(max(a, b), c)
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
/**************BASHAR*****************/
int n, k, arr[100001], cnt, xx = -1;
int main() {
	file();
	scan(n), scan(k);
	for (int i = 0; i < n; i++) {
		scan(arr[i]);
	}
	for (int i = 0; i < n; i++) {

		if (arr[i] < 0 && k > 0)
			arr[i] *= -1, k--;
		cnt += arr[i];

	}
	if (k % 2 && k > 0)
		sort(arr, arr + n), cnt -= arr[0] * 2;

	printf("%d", cnt);
}
