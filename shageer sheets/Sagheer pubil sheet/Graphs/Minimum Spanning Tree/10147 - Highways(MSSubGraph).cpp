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
int n, m, u, v, t, from[751], to[751], cnt;
vector<pair<double, pi>> EdgeList;
class UnionFind {
private:
	vi p, rank, setSize;
	int numSets;
public:
	UnionFind(int N) {
		setSize.assign(N + 1, 1);
		numSets = N;
		rank.assign(N + 1, 0);
		p.assign(N + 1, 0);
		for (int i = 1; i <= N; i++)
			p[i] = i;
	}
	int findSet(int i) {
		return (p[i] == i) ? i : (p[i] = findSet(p[i]));
	}
	bool isSameSet(int i, int j) {
		return findSet(i) == findSet(j);
	}
	bool unionSet(int i, int j) {
		if (isSameSet(i, j)) {
			return false;
		} else {
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
		return true;
	}
	int numDisjointSets() {
		return numSets;
	}
	int sizeOfSet(int i) {
		return setSize[findSet(i)];
	}
};
double dis(int x, int y) {
	return sqrt(pow(from[x] - from[y], 2) + pow(to[x] - to[y], 2));
}
int main() {
	file();
	scanf("%d", &t);
	while (t--) {
		cnt = 0;
		mem(from,-1), mem(to, -1), EdgeList.clear();
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d%d", &from[i], &to[i]);
		}
		scanf("%d", &m);
		UnionFind UF(n);
		for (int i = 0; i < m; i++) {
			scanf("%d%d", &u, &v);
			UF.unionSet(u, v);
		}
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				EdgeList.push_back(make_pair(dis(i, j), make_pair(i, j)));
			}
		}
		sort(EdgeList.begin(), EdgeList.end());
		for (int i = 0; i < sz(EdgeList); i++) {
			pair<double, pi> cur = EdgeList[i];
			if (UF.unionSet(cur.second.first, cur.second.second)) {
				printf("%d %d\n", cur.second.first, cur.second.second);
				cnt++;
			}
		}
		if (!cnt)
			printf("%s", "No new highways need\n");
		if (t)
			printf("\n");

	}
}
