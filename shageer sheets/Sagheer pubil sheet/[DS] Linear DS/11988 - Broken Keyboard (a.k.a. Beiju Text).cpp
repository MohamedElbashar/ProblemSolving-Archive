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
int main() {
	file();
	string s;
	list<char> li;
	list<char>::iterator it;
	while (getline(cin, s)) {
		li.clear();
		it = li.begin();
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '[')
				it = li.begin();
			if (s[i] == ']')
				it = li.end();
			if (s[i] != ']' && s[i] != '[')
				li.insert(it, s[i]);
		}
		for (it = li.begin(); it != li.end(); it++) {
			printf("%c", *it);
		}
		printf("\n");
	}
}
