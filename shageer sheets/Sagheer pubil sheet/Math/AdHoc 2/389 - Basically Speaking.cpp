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
#define maxx(a, b, c) max(max(a,	 b), c)
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
ll a, b;
char s[100];

int Value(char ch) {
	if ('0' <= ch && ch <= '9')
		return (ch - 48);
	else
		return (ch - 55);
}

char Char(int val) {
	if (0 <= val && val <= 9)
		return (val + 48);
	else
		return (val + 55);
}

int main() {
	file();
	while (scanf(" %s %d %d", &s, &a, &b) != EOF) {
		ll rs = 0;
		for (int i = 0, len = strlen(s); i < len; i++)
			rs = rs * a + Value(s[i]);
		int len = 0;
		while (rs) {
			s[len++] = Char(rs % b);
			rs /= b;
		}
		if (len > 7)
			puts("  ERROR");
		else {
			if (len == 0)
				s[len++] = '0';
			for (int i = len; i <= 6; i++)
				printf(" ");
			for (int i = len - 1; i >= 0; i--)
				printf("%c", s[i]);
			printf("\n");
		}
	}
}

