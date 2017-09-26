#include <bits/stdc++.h>
using namespace std;
/**************BASHAR*****************/
struct node {
	int v, u, c;
	node(int v, int u, int c) :
			v(v), u(u), c(c) {
	}
	bool operator <(const node &e) const {
		return c > e.c;
	}
};
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
#define rep( i, n ) for (int i = 0; i < (n); i++)
#define scan(n) scanf("%d",&n)
#define mem(a,b) memset(a,b,sizeof(a))
#define ll long long
#define oo 1e9
int di[] = { 1, -1, 0, 0 };
int dj[] = { 0, 0, 1, -1 };
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//	freopen("out.txt", "w", stdout);
#else
	// online submission
	//freopen("interesting.in", "r", stdin);
#endif
}
/**************BASHAR*****************/
string s1, s2;
int cnts1, cnts2, cntq;
vector<string> s;
int cnt, ans;
int solve(char arr[], string str, int n, int k) {
	if (cntq == 0) {
		s.clear();
		return 0;
	}
	if (k == 1) {

		for (int j = 0; j < n; j++)
			s.push_back(str + arr[j]);
	} else {

		for (int i = 0; i < n; i++)
			solve(arr, str + arr[i], n, k - 1);
	}
}
int main() {
	file();
	cin >> s1 >> s2;
	for (int i = 0; i < s1.length(); i++) {
		if (s1[i] == '+')
			cnts1++;
		else if (s1[i] == '-')
			cnts1--;
	}
	for (int i = 0; i < s2.length(); i++) {
		if (s2[i] == '+')
			cnts2++;
		else if (s2[i] == '-')
			cnts2--;
		else if (s2[i] == '?')
			cntq++;
	}
	if (!cntq && cnts1 == cnts2) {
		double z = (double) 1;
		cout << fixed << setprecision(12) << z << endl;
	} else {
		char arr[] = { '+', '-' };
		int n = sizeof set;
		int ss = solve(arr, "", n, cntq);
		for (int i = 0; i < s.size(); i++) {
			for (int j = 0; j < s[i].length(); j++) {
				if (s[i][j] == '+') {
					cnt++;
				} else if (s[i][j] == '-') {
					cnt--;
				}
			}
			if (cnt + cnts2 == cnts1) {
				ans++;
			}
			cnt = 0;
		}
		int sz = s.size();
		double xx=0.0;
		if (sz) {
			xx = (double) ans / sz;
		}
		cout << fixed << setprecision(12) << xx;
	}
}
