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

int main() {
	file();
	int E, V, u, v, w;
	vector<pair<int, pi>> EdgeList;  // (weight, two vertices) of the edge
	scanf("%d%d", &V, &E);
	for (int i = 0; i < E; i++) {
		scanf("%d%d%d", &u, &v, &w);  // read the triple: (u, v, w)
		EdgeList.push_back(mp(w, mp(u, v)));  // (w, u, v)
	}
	sort(EdgeList.begin(), EdgeList.end()); // sort by edge weight O(E log E)
	// note: pair object has built-in comparison function
	int MstCost = 0;
	UnionFind UF(V);   // all V are disjoint sets initially
	for (int i = 0; i < E; i++) {	// for each edge, O(E)
		pair<int, pi> front = EdgeList[i];
		if (!UF.isSameSet(front.second.first, front.second.second)) {	// check
			MstCost += front.first;			// add the weight of e to MST
			UF.unionSet(front.second.first, front.second.second);	// link them
		}
		// note: the runtime cost of UFDS is very light
	}
	// note: the number of disjoint sets must eventually be 1 for a valid MST
	printf("MST cost = %d (Kruskal’s)\n", MstCost);
}
