#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pi> vpi;
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define mem(a,b) memset(a,b,sizeof a)
#define sz(v) ((int)((v).size()))
#define minn(a, b, c) min(min(a, b), c)
#define maxx(a, b, c) max(max(a, b), c)and
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
//\/\/\/\/\/\/\/\/\/\/\/\/\/\//\/\/\/\//\/\/\/\/\/\/\/\/\/\/
int main() {
	file();
	string a, b, c;

	while (cin >> a >> b >> c) {

		int alen = a.length();
		int blen = b.length();
		int clen = c.length();

		vi cntA(26), cntB(26), cntC(26);

		for (int i = 0; i < alen; i++) {
			cntA[a[i] - 'a']++;
		}

		for (int i = 0; i < blen; i++) {
			cntB[b[i] - 'a']++;
		}

		for (int i = 0; i < clen; i++) {
			cntC[c[i] - 'a']++;
		}

		int cnt1 = 0, cnt2 = 0;

		for (int i = 0; i <= alen; i++) {

			int f = 1;

			for (int j = 0; j < 26; j++) {
				if (cntA[j] < i * cntB[j]) {
					f = 0;
					break;
				}
			}

			if (f == 0) {
				break;
			}

			int cmx = alen;
			for (int j = 0; j < 26; j++) {
				if (cntC[j]) {
					cmx = min(cmx, (cntA[j] - i * cntB[j]) / cntC[j]);
				}
			}

			if (cmx + i >= cnt1 + cnt2) {
				cnt1 = i;
				cnt2 = cmx;
			}

		}

		string s = "";
		for (int i = 0; i < cnt1; i++) {
			s += b;
		}

		for (int i = 0; i < cnt2; i++) {
			s += c;
		}

		for (int i = 0; i < 26; i++) {

			for (int j = 0; j < cntA[i] - cntB[i] * cnt1 - cntC[i] * cnt2;
					j++) {
				s += char(i + 'a');
			}

		}

		cout << s << "\n";

	}

	return 0;
}

