#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
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
int n, m, u, v, c, t, tot;
vi key;
vector<pair<int, pi>> arr;
class UnionFind {
private:
	vi p, rank, setSize;
	int numSets;
public:
	UnionFind(int N) {
		setSize.assign(N + 1, 1);
		numSets = N;
		rank.assign(N + 1, 0);
		p.assign(N + 1, -1);
		for (int i = 0; i < N; i++)
			p[i] = i;
	}
	int findSet(int i) {
		return (p[i] == i) ? i : (p[i] = findSet(p[i]));
	}
	bool isSameSet(int i, int j) {
		return findSet(i) == findSet(j);
	}
	void unionSet(int i, int j) {
		if (!isSameSet(i, j)) {
			numSets--;
			int x = findSet(i), y = findSet(j);
			if (rank[x] > rank[y]) {
				p[y] = x;
				setSize[x] += setSize[y];
			} else {
				p[x] = y;
				setSize[y] += setSize[x];
				if (rank[x] == rank[y])
					rank[y]++;
			}
		}
	}
	int numDisjointSets() {
		return numSets;
	}
	int sizeOfSet(int i) {
		return setSize[findSet(i)];
	}
};
int getDist(int x, int y) {
	int ans = 0, d;
	for (int i = 0; i < 4; ++i, x /= 10, y /= 10)
		d = abs(x % 10 - y % 10), ans += min(d, 10 - d);
	return ans;
}
int tt;
int main() {
	file();
	//b3ml simulate llgraph bas
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		key.clear();
		arr.clear();
		for (int i = 0; i < n; i++) {
			scanf("%d", &u);
			key.push_back(u);
		}
		int cnt = oo;
		for (int i = 0; i < n; i++) {
			cnt = min(cnt, getDist(0, key[i]));
			for (int j = i + 1; j < n; j++) {
				arr.push_back(mp(getDist(key[i], key[j]), mp(i, j)));
			}
		}
		sort(all(arr));
		UnionFind uf(n + 1);
		for (int i = 0; i < sz(arr); i++) {
			pair<int, pi> cur = arr[i];
			if (!uf.isSameSet(cur.second.first, cur.second.second)) {
				uf.unionSet(cur.second.first, cur.second.second);
				cnt += cur.first;
			}
		}
		printf("%d\n", cnt);
	}

}
