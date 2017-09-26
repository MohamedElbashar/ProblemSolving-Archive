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

map<string, int> M;

void generate_positions() {
	queue<string> Q;
	for (char c = 'a'; c <= 'z'; c++)
		Q.push(string(1, c));

	string s;

	int cont = 1;

	while (!Q.empty()) {
		s = Q.front();
		Q.pop();

		M[s] = cont;
		cont++;

		if (s.size() == 5)
			continue;

		for (char c = s[s.size() - 1] + 1; c <= 'z'; c++)
			Q.push(s + c);
	}
}

int main() {
	file();
	generate_positions();

	string s;
	map<string, int>::iterator it;

	while (cin >> s) {
		it = M.find(s);
		if (it == M.end())
			cout << 0 << endl;
		else
			cout << it->second << endl;
	}

	return 0;
}
