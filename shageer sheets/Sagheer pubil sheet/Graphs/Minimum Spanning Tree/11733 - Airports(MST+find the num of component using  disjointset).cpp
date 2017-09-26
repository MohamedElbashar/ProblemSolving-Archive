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
vector<pair<int, pi>> arr;
vi p;
class UnionFind {
private:
	vi rank, setSize;
	int numSets;
public:
	UnionFind(int N) {
		setSize.assign(N + 1, 1);
		numSets = N;
		rank.assign(N + 1, 0);
		p.assign(N + 1, -1);
		for (int i = 1; i <= N; i++)
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
int tt;
int main() {
	file();
	/*talma en p[i] el index 4abah ba3do yb2a enta keda fe commponet wa7ed
	 * lken lw et8yer yb2a keda enta d5lt 3ala component tane
	 * 3 3 3 3 5 5 keda 2 component wa7ed el parent bta3o b 3 wl tane b 5
	 * */
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d", &n, &m, &tot);
		for (int i = 0; i < m; i++) {
			scanf("%d%d%d", &u, &v, &c);
			arr.push_back(mp(c, mp(u, v)));
		}
		UnionFind uf(n);
		int cnt = 0, air = 0;
		sort(arr.begin(), arr.end());
		for (int i = 0; i < sz(arr) && arr[i].first < tot; i++) {
			pair<int, pi> cur = arr[i];
			if (!uf.isSameSet(cur.second.first, cur.second.second)) {
				uf.unionSet(cur.second.first, cur.second.second);
				cnt += cur.first;
			}
		}
		for (int i = 1; i <= n; i++) {
			cnt += tot * (p[i] == i);
			air += (p[i] == i);
		}
		printf("Case #%d: %d %d\n", ++tt, cnt, air);
		p.clear(), arr.clear();
	}

}
