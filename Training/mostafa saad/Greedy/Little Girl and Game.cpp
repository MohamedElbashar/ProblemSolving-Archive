#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
#define ll long long
#define mem(a,b) memset(a,b,sizeof a)
#define oo 1e8
#define minn(a, b, c) min(min(a, b), c)
#define maxx(a, b, c) max(max(a, b), c)
int dx[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
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
//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\//\/\/\/\/\/\/\/\/\/pi arr[1000001];
int n, flag, arr[30];
int main() {
	file();
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		arr[s[i] - 'a']++;
	}
	int cnt = 0;
	for (int i = 0; i < 26; i++) {
		if (arr[i] % 2)
			cnt++;
	}
	if (cnt % 2 || cnt == 0)
		printf("%s", "First");
	else
		printf("%s", "Second");

}
