#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<pi> vpi;
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define mem(a,b) memset(a,b,sizeof a)
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
	//freopen("sets.in", "r", stdin);
#endif
}
//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\//\/\/\/\/\/\/\/\/\/\/
int n;
int main() {
	file();
	while (scanf("%d", &n) && (n > 0)) {
		int prem = 0, comb = 0;
		for (int i = 0; i < 61; i++) {
			if (i <= 20 || (i % 2 == 0 && i <= 40) || (i % 3 == 0) || i == 50)
				for (int j = 0; j < 61; j++) {
					if (j <= 20 || (j % 2 == 0 && j <= 40) || (j % 3 == 0)
							|| j == 50)
						for (int k = 0; k < 61; k++) {
							if (k <= 20 || (k % 2 == 0 && k <= 40)
									|| (k % 3 == 0) || k == 50) {
								if (i + j + k == n)
									prem++;
							}
						}
				}
		}
		for (int i = 0; i < 61; i++) {
			if (i <= 20 || (i % 2 == 0 && i <= 40) || (i % 3 == 0) || i == 50)
				for (int j = i; j < 61; j++) {
					if (j <= 20 || (j % 2 == 0 && j <= 40) || (j % 3 == 0)
							|| j == 50)
						for (int k = j; k < 61; k++) {
							if (k <= 20 || (k % 2 == 0 && k <= 40)
									|| (k % 3 == 0) || k == 50) {
								if (i + j + k == n)
									comb++;
							}
						}
				}
		}
		if (!prem)
			printf(
					"THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n**********************************************************************\n",
					n);
		else
			printf(
					"NUMBER OF COMBINATIONS THAT SCORES %d IS %lld.\nNUMBER OF PERMUTATIONS THAT SCORES %d IS %lld.\n**********************************************************************\n",
					n, comb, n, prem);
	}
	puts("END OF OUTPUT");

	return 0;

}
