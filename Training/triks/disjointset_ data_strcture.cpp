#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
#define ll long long
#define mem(a,b) memset(a,b,sizeof a)
#define oo 1e8
#define minn(a, b, c) min(min(a, b), c)
#define maxx(a, b, c) max(max(a, b), c)
int dx[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
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

//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\//\/\/\/\/\/\/\/\/\/
struct unionfind {
	vi rank, parent;
	int forests;
	unionfind(int n) {
		rank = vi(n), parent = vi(n);
		forests = n;	//number of current forests
		for (int i = 0; i < n; i++) {
			//kol node el parent bta3ha nafsha
			parent[i] = i;
			rank[i] = 1;
		}
	}
	int find_parent(int x) {
		//while(x!=parent[x]) x=parent[x];
		//hena ana 3and el top parent;
		if (x == parent[x])
			return x;
		/*hena hyro7 y4of kol el parent bta3 el node w ema ywsal lltopparent
		 * 5le el node ele ana kont bade2 men 3ndha el parent bta3ha el top parent
		 */
		return parent[x] = find_parent(parent[x]);
	}
	void link(int x, int y) {
		if (rank[x] > rank[y])
			swap(x, y);
		//hena ana damen en el x howa el so8yr y3ml b2a link el x fe el y
		parent[x] = y;
		//lw kano 2ad ba3d yb2a el rank bta3 el y hyzed b 1 ersmha htfhm aktar
		if (rank[x] == rank[y])
			rank[y]++;

	}
	bool unionset(int x, int y) {
		//3wz arbot 2 forests bb3d
		x = find_parent(x), y = find_parent(y);
		//lw el parent mo5tlf yb2a e4ta ynf3 tlinkhm m3 b3d wna2s 3dd el forests b 1
		if (x != y) {
			link(x, y);
			forests--;
		}
		return x != y;
	}
	int same_set(int x, int y) {
		return find_parent(x) == find_parent(y);
	}
	vector<vi> connected_components() {
		vector<vi> list(parent.size());
		for (int i = 0; i < parent.size(); i++) {
			list[find_parent(i)].push_back(i);
		}
		return list;
	}
};

int main() {

	file();

}
