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
string s;
map<string, int> mp;
map<string, int>::iterator it;
int main() {
	file();
	int cnt = 1;
	for (char i = 'a'; i <= 'z'; i++) {
		string ss;
		ss.push_back(i);
		mp[ss] = cnt;
		cnt++;
	}
	for (char i = 'a'; i <= 'z'; i++) {
		for (char j = i + 1; j <= 'z'; j++) {
			string ss;
			ss.push_back(i), ss.push_back(j);
			mp[ss] = cnt;
			cnt++;
		}
	}
	for (char i = 'a'; i <= 'z'; i++) {
		for (char j = i + 1; j <= 'z'; j++) {
			for (char k = j + 1; k <= 'z'; k++) {
				string ss;
				ss.push_back(i), ss.push_back(j), ss.push_back(k);
				mp[ss] = cnt;
				cnt++;
			}
		}
	}
	for (char i = 'a'; i <= 'z'; i++) {
		for (char j = i + 1; j <= 'z'; j++) {
			for (char k = j + 1; k <= 'z'; k++) {
				for (char q = k + 1; q <= 'z'; q++) {
					string ss;
					ss.push_back(i), ss.push_back(j), ss.push_back(k), ss.push_back(
							q);
					mp[ss] = cnt;
					cnt++;
				}
			}
		}
	}
	for (char i = 'a'; i <= 'z'; i++) {
		for (char j = i + 1; j <= 'z'; j++) {
			for (char k = j + 1; k <= 'z'; k++) {
				for (char q = k + 1; q <= 'z'; q++) {
					for (char c = q + 1; c <= 'z'; c++) {
						string ss;
						ss.push_back(i), ss.push_back(j), ss.push_back(k), ss.push_back(
								q), ss.push_back(c);
						mp[ss] = cnt;
						cnt++;
					}
				}
			}

		}
	}
	while (cin >> s) {
		it = mp.find(s);
		if (it == mp.end())
			printf("%d\n", 0);
		else {
			printf("%d\n", it->second);
		}
	}
	return 0;

}
