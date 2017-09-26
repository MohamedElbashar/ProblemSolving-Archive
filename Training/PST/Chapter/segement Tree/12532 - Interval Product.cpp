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
//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\//\/\/\/\/\/\/\/\/\/
const int N = 100000 + 5;
int arr[N];
int tree[4 * N];
int merge(int x, int y) {
	return x * y;
}
void build(int ind, int st, int en) {

	if (st == en) {
		tree[ind] = arr[st];
		if (arr[st] < 0)
			tree[ind] = -1;
		else if (arr[st] > 0)
			tree[ind] = 1;
		else
			tree[ind] = 0;
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
		return 1;

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
		if (val < 0)
			tree[pos] = -1;
		else if (val > 0)
			tree[pos] = 1;
		else
			tree[pos] = 0;
		return;
	}

	int mid = (st + en) / 2;
	int left = 2 * pos;
	int right = 2 * pos + 1;

	update(left, st, mid, idx, val);
	update(right, mid + 1, en, idx, val);

	tree[pos] = merge(tree[right], tree[left]);
}
int n, k;
int main() {
	file();
	while (cin >> n >> k) {
		for (int i = 0; i < 4 * N; i++)
			tree[i] = 1;
		for (int i = 1; i <= n; i++)
			cin >> arr[i];
		build(1, 1, n);
		char c;
		for (int i = 0; i < k; i++) {
			cin >> c;
			if (c == 'C') {
				int idx;
				int val;
				cin >> idx >> val;
				update(1, 1, n, idx, val);
			} else {
				int st, en;
				cin >> st >> en;
				int res = query(1, 1, n, st, en);
				if (res > 0)
					cout << "+";
				else if (res < 0)
					cout << "-";
				else
					cout << "0";

			}
		}

		cout << endl;
	}

	return 0;
}
