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

#define MAX 1000
struct Item {
	string s;
	int c;
	Item(string s, int c) :
			s(s), c(c) {
	}
};

string replace(string str, string from, string to) {
	if (from.empty())
		return str;
	int start_pos = 0;
	while ((start_pos = str.find(from, start_pos)) != string::npos) {
		str.replace(start_pos, from.length(), to);
		start_pos += to.length();
	}
	return str;
}

int n;
string A[MAX], B[MAX];

int main() {
	file();
	while (cin >> n, n) {
		for (int i = 0; i < n; i++)
			cin >> A[i] >> B[i];
		string a, b;
		cin >> a >> b;

		queue<Item> Q;
		set<string> S;
		Q.push(Item(a, 0));

		int answer = -1;
		while (!Q.empty()) {
			Item e = Q.front();
			Q.pop();
			if (e.s == b) {
				answer = e.c;
				break;
			}

			if (S.find(e.s) != S.end())
				continue;
			S.insert(e.s);

			for (int i = 0; i < n; i++) {
				string s = replace(e.s, A[i], B[i]);
				if (S.find(s) != S.end() || s.size() > 10)
					continue;
				Q.push(Item(s, e.c + 1));
			}
		}

		cout << answer << endl;

	}

}
