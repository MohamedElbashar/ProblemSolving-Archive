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
#define all(v) v.begin(), v.end()
#define turnOnLastZero(S) ((S) | (S + 1))
#define maxx(a, b, c) max(max(a, b), c)
int dx[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int di[] = { 1, -1, 0, 0 };
int dj[] = { 0, 0, 1, -1 };
#define isOn(S, j) (S & (1 << j))
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
class Packet {
public:
	int ss, ee, id;
};
Packet nP(int x, int y, int z) {
	Packet p;
	p.id = x, p.ss = y, p.ee = z;
	return p;
}

int main() {
	file();
	int n, m, ttt = 0;
	while (scanf("%d%d", &n, &m) && n && m) {
		int id, ss, ee, order[7] { 0, 1, 2, 3, 4, 5, 6 }, ndB = oo, s[7] { 0 };
		Packet seq[1002];
		for (int i = 1; i <= n; scanf("%d", &s[i]), ++i)
			;
		for (int i = 0; i < m and scanf("%d%d%d", &id, &ss, &ee); ++i)
			seq[i] = nP(id, ss, ee);
		do {
			int mxB = 0, cs = 0, cM = order[1], cB = 1, mIdx = 1;
			vi bytes[7];
			for (int i = 0; i < 7; ++i)
				for (int j = 0; j < s[i] + 4; ++j)
					bytes[i].push_back(0);
			for (int i = 0; i < m; ++i) {
				Packet p = seq[i];
				for (int i = p.ss; i <= p.ee; ++i)
					bytes[p.id][i] = 1;
				cs += p.ee - p.ss + 1;
				while (mIdx <= n) {
					while (cB <= s[cM] and bytes[cM][cB])
						cB++, cs--;
					if (cB <= s[cM] or mIdx == n)
						break;
					cB = 1, cM = order[++mIdx];
				}
				mxB = max(mxB, cs);
			}
			ndB = min(ndB, mxB);
		} while (next_permutation(order + 1, order + n + 1));
		printf("Case %d: %d\n\n", ++ttt, ndB);
	}
	return 0;
}
