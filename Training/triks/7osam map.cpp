#include <bits/stdc++.h>
using namespace std;
/**************BASHAR*****************/
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
typedef set<string> ss;
#define rep( i, n ) \
	for ( int i = 0; i < (n); i++ )

#define mem(a,b) memset(a,b,sizeof(a))
#define ll long long
#define oo 1e9
#define fir first
#define sec second
int di[] = { 1, -1, 0, 0 };
int dj[] = { 0, 0, 1, -1 };
void file() {
#ifndef ONLINE_JUDGE
	//freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#else
// online submission
	freopen("coaches.in", "r", stdin);
#endif
}
/**************BASHAR*****************/
void run(map<string, ss> &dta) {

	map<string, ss>::iterator itdd;
	map<string, vector<map<string, ss>::iterator> > cnt;
	map<string, vector<map<string, ss>::iterator> >::iterator count;

	for (itdd = dta.begin(); itdd != dta.end(); itdd++) {
		set<string> &current = itdd->second;
		set<string>::iterator it = current.begin();
		for (; it != current.end(); it++) {
			cnt[*it].push_back(itdd);
		}
	}

	for (count = cnt.begin(); count != cnt.end(); count++) {
		if (count->second.size() > 1) {
			for (int i = 0; i < (int) count->second.size(); i++) {
				count->second[i]->second.erase(count->first);
			}
		}
	}
	map<int, set<string> > ans;
	for (itdd = dta.begin(); itdd != dta.end(); itdd++) {
		ans[-itdd->second.size()].insert(itdd->first);
	}

	for (auto a : ans) {
		for (auto b : a.second) {
			printf("%s %d\n", b.c_str(), -a.first);
		}
	}
}
bool check(string a) {
	for (int i = 0; i < (int) a.size(); ++i)
		if (isupper(a[i]))
			return 1;
	return 0;
}
int main() {
	file();
	long long t;
	scanf("%d", &t);
	while (t--) {
		int n;
		map<string, ss> mp;
		string ans = "", str = "";
		scanf("%d\n", &n);
		while (n--) {
			getline(cin, str);
			if (check(str)) {
				ans = str;
				mp[ans];
			} else {
				mp[ans].insert(str);
			}
		}
		run(mp);
	}
	return 0;
}
