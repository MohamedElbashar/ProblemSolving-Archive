#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
#define PI 3.1415926535897932384626433832795
#define EPS  1e-10
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
using namespace std;
int main() {
	file();
	string s;
	set<string> words;
	while (getline(cin, s)) {
		transform(s.begin(), s.end(), s.begin(), ::tolower);
		string str = "";
		for (int i = 0; i <(int) s.length(); ++i) {
			if (isalpha(s[i]))
				str += s[i];
			else if (str != "") {
				words.insert(str);
				str = "";
			}
		}
		if (str != "")
			words.insert(str);
	}

	for (set<string>::iterator it = words.begin(); it != words.end(); ++it)
		cout << *it << '\n';
}
