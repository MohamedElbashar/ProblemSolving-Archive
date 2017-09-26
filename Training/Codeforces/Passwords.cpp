#include <bits/stdc++.h>
using namespace std;
/**************BASHAR*****************/
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
#define mem(a,b) memset(a,b,sizeof(a))
#define ll long long
#define oo 1e9
#define fir first
#define sec second
int di[] = { 1, -1, 0, 0 };
int dj[] = { 0, 0, 1, -1 };
/**************BASHAR*****************/
int cmp(pair<char, int> a, pair<char, int> b) {
	if (a.sec == b.sec)
		return a.fir < b.fir;
	else
		return a.sec < b.sec;
}
int t;
string s;

int main() {
	scanf("%d", &t);
	while (t--) {
		vector<pair<char, int> > v;
		map<char, int> mp;
		cin >> s;
		for (int i = 0; i < s.length(); i++) {
			mp[s[i]]++;
		}
		for (map<char, int>::iterator it = mp.begin(); it != mp.end(); ++it) {
			v.push_back(make_pair(it->first, it->second));
		}
		sort(v.begin(), v.end(), cmp);
		int x = (int) v.size();
		int xx = x / 2;
		if (v.size() % 2) {
			cout << v[xx].first << endl;
		} else {
			cout << v[xx-1].first << v[xx].first << endl;
		}

	}
}
