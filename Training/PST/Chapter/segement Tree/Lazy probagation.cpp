#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
#define PI 3.1415926535897932384626433832795
#define ll long long
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define mem(a,b) memset(a,b,sizeof a)
#define oo 1e8
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
	//freopen("interesting.in", "r", stdin);
#endif
}
//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\//\/\/\/\/\/\/\/\/\/typedef long long ll;

const int N = (1 << 18);
const ll OO = (ll) 1 * 1e18;
ll arr[N + 2];
ll tree[2 * N];
ll lazy[2 * N];
struct SegmentTree {

	SegmentTree() {

	}
	void build(int cur, int l, int r) {
		lazy[cur] = 0;
		if (l == r) {
			tree[cur] = arr[l];
			return;
		}
		int left = 2 * cur;
		int right = 2 * cur + 1;
		int mid = (l + r) / 2;
		build(left, l, mid);
		build(right, mid + 1, r);
		tree[cur] = min(tree[left], tree[right]);
	}

	void update(int cur, int l, int r, int ind, ll val) {
		if (ind < l || ind > r)
			return;
		if (l == r && ind == l) {
			tree[cur] += val;
			return;
		}
		int left = 2 * cur;
		int right = 2 * cur + 1;
		int mid = (l + r) / 2;
		update(left, l, mid, ind, val);
		update(right, mid + 1, r, ind, val);
		tree[cur] = min(tree[left], tree[right]);
	}

	void propagte(int cur, int l, int r, int left, int right) {
		if (lazy[cur] != 0) {
			tree[cur] += lazy[cur];
			if (l != r) {
				lazy[left] += lazy[cur];
				lazy[right] += lazy[cur];
			}
			lazy[cur] = 0;
		}
	}

	void updateRange(int cur, int l, int r, int x, int y, ll val) {
		int left = 2 * cur;
		int right = 2 * cur + 1;
		int mid = (l + r) / 2;

		propagte(cur, l, r, left, right);

		if (l > y || x > r)
			return;

		if (l >= x && r <= y) {
			lazy[cur] += val;
			propagte(cur, l, r, left, right);
			return;
		}

		updateRange(left, l, mid, x, y, val);
		updateRange(right, mid + 1, r, x, y, val);
		tree[cur] = min(tree[left], tree[right]);
	}

	ll getAnswer(int cur, int l, int r, int x, int y) {
		int left = 2 * cur;
		int right = 2 * cur + 1;
		int mid = (l + r) / 2;

		propagte(cur, l, r, left, right);

		if (y < l || x > r)
			return OO;
		if (l >= x && r <= y)
			return tree[cur];

		ll res1 = getAnswer(left, l, mid, x, y);
		ll res2 = getAnswer(right, mid + 1, r, x, y);
		return min(res1, res2);
	}
};
int main() {
}
