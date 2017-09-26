#include <bits/stdc++.h>
using namespace std;
//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\//\/\/\/\/\/\/\/\/\/
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
int cnt[26];
int main() {
	file();
	string s, t;
	cin >> s >> t;
	int lens = s.size();
	int legt = t.size();
	int j = 0;
	for (int i = 0; i < lens; i++) {
		if (s[i] == t[j]) {
			j++;
		}
	}
	if (j == legt) {
		printf("%s", "automaton");
		return 0;
	}
	for (int i = 0; i < lens; i++) {
		cnt[s[i] - 'a']++;
	}
	for (int i = 0; i < legt; i++) {
		cnt[t[i] - 'a']--;
	}
	for (int i = 0; i < 26; i++) {
		if (cnt[i] < 0) {
			printf("%s", "need tree");
			return 0;
		}
	}
	if (lens == legt) {
		printf("%s", "array");
		return 0;
	} else {
		printf("%s", "both");
		return 0;
	}

}
