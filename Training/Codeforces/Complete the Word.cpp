#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
#define ll long long
#define oo 1e8
#define minn(a, b, c) min(min(a, b), c)
#define maxx(a, b, c) max(max(a, b), c)
int di[] = { 0, -1, 0, 1 };
int dj[] = { 0, 1, 1, 1 };
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
char cnt[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
		'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
int arr[26], ch[26], ret;
int main() {
	file();
	vi v;
	string s;
	set<char> ss;
	cin >> s;
	for (int i = 1; i <= (int) s.size(); i++) {
		if (s[i - 1] != '?') {
			arr[s[i - 1] - 'A'] = s[i - 1] - 'A' + 1;
			ch[s[i - 1] - 'A']++;
			ss.insert(s[i - 1]);
		} else
			v.push_back(i - 1);
	}
	if (v.size()) {
		for (int i = 0; i < (int) v.size(); i++) {
			for (int j = 0; j < 26; j++) {
				if (ch[j] == 0) {
					s[v[i]] = cnt[j];
					ch[j]++;
					break;
				}
			}
			if (s[v[i]]=='?')
				s[v[i]] = 'A';
		}
		cout << s;
		return 0;
	} else {
		printf("%d", -1);
		return 0;
	}
}
