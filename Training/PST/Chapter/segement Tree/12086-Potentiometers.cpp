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
	freopen("out.txt", "w", stdout);
#else
	// online submission
	//freopen("interesting.in", "r", stdin);
#endif
}
//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\//\/\/\/\/\/\/\/\/\/
const int N = 200000 + 5;
int arr[N], n;
int tree[4 * N];

int merge(int x, int y) {
	return x + y;
}
;
void build(int ind, int st, int en) {

	if (st == en) {
		tree[ind] = arr[st];
		return;
	}

	int mid = (st + en) / 2;
	int right = 2 * ind + 1;
	int left = 2 * ind;

	build(left, st, mid);
	build(right, mid + 1, en);

	tree[ind] = merge(tree[right], tree[left]);
}

int query(int ind, int st, int en, int i, int j) {
	if (j < st || en < i)			// no intersect
		return 0;

	if (i <= st && en <= j)  		// begin & end in [i ... j]
		return tree[ind];

	int mid = (st + en) / 2;
	int left = 2 * ind;
	int right = 2 * ind + 1;

	int q1 = query(left, st, mid, i, j);
	int q2 = query(right, mid + 1, en, i, j);

	return merge(q1, q2);
}
void update(int pos, int st, int en, int idx, int val) {
	if (idx < st || idx > en)
		return;

	if (st == en && idx == en) {
		tree[pos] = val;
		arr[idx] = val;
		return;
	}
	int mid = (st + en) / 2;
	int left = 2 * pos;
	int right = 2 * pos + 1;

	update(left, st, mid, idx, val);
	update(right, mid + 1, en, idx, val);

	tree[pos] = merge(tree[right], tree[left]);
}
int main() {
	file();
}

