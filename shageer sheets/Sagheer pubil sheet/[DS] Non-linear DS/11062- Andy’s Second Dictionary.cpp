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
set<string> st;
int main() {
	file();
	string s, str;
	while (getline(cin, s)) {
		transform(s.begin(), s.end(), s.begin(), ::tolower);
		int i = 0;
		for (i = 0; i < (int) s.size() + 1; i++) {
			if (isalpha(s[i])) {
				str.push_back(s[i]);
			} else if (s[i] == '-') {
				if (i != (int) s.length() - 1) {
					str.push_back(s[i]);
				} else {
					break;
				}
			} else {
				st.insert(str);
				str.clear();
			}
		}
		/*if (i == (int) s.length() && str != "") {
		 st.insert(str);
		 }*/
	}
	int len = st.size();
	while (!st.empty()) {
		string ss = *st.begin();
		st.erase(st.begin());
		if (ss == "")
			continue;

		cout << ss << endl;
	}
}
