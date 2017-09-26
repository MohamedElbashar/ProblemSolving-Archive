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
	char s[64];
	vi v;
	gets(s);
	while (gets(s)) {
		if (s[0] == '_')
			break;
		for (int i = 0; i < strlen(s); i++) {
			if (s[i] == ' ')
				v.push_back(0);
			else if (s[i] == 'o')
				v.push_back(1);
		}
		int sum = 0;
		reverse(v.begin(), v.end());
		for (int i = 0; i < sz(v); i++) {
			sum += v[i] * pow(2, i);
		}
		cout << (char) sum;
		v.clear();
	}
}
