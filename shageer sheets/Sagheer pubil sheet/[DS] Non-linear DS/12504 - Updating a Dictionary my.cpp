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

int t;

string num, key;
map<string, string> solve(string str) {
	map<string, string> mp;
	for (int i = 0; i < (int) str.length(); i++) {
		if (isalpha(str[i])) {
			key.push_back(str[i]);
		} else if (isalnum(str[i])) {
			num.push_back(str[i]);
		} else if (str[i] == ':')
			continue;
		else if (str[i] == ',' || str[i] == '}') {
			mp[key] = num;
			key.clear();
			num.clear();
		}
	}
	return mp;
}
int main() {
	file();
	string str, str2;
	scanf("%d", &t);
	getchar();
	while (t--) {
		getline(cin, str);
		getline(cin, str2);
		vector<string> v1, v2, tie;
		map<string, string> mp1;
		map<string, string> mp2;
		mp1 = solve(str);
		mp2 = solve(str2);
		int flag = 0;
		for (map<string, string>::iterator it = mp1.begin(); it != mp1.end();
				it++) {
			for (map<string, string>::iterator it2 = mp2.begin();
					it2 != mp2.end(); it2++) {
				if (it->first == it2->first && it->second != it2->second)
					tie.push_back(it2->first);
				if (!flag) {
					map<string, string>::iterator nw = mp1.find(it2->first);
					if (nw == mp1.end()) {
						v1.push_back(it2->first);
					}
				}
			}

			flag = 1;
			map<string, string>::iterator nw = mp2.find(it->first);
			if (nw == mp2.end()) {
				v2.push_back(it->first);
			}
		}
		int x = v1.size(), y = v2.size(), z = tie.size();
		if (x || y || z) {
			for (int i = 0; i < x; i++) {
				if (i == 0 && isalpha(v1[i][0]))
					cout << "+" << v1[i];

				else if (isalpha(v1[i][0]))
					cout << "," << v1[i];
				if (i == x - 1 && isalpha(v1[i][0]))
					cout << endl;

			}
			for (int i = 0; i < y; i++) {
				if (i == 0 && isalpha(v2[i][0]))
					cout << "-" << v2[i];

				else if (isalpha(v2[i][0]))
					cout << "," << v2[i];
				if (i == y - 1 && isalpha(v2[i][0]))
					cout << endl;

			}
			for (int i = 0; i < z; i++) {
				if (i == 0 && isalpha(tie[i][0]))
					cout << "*" << tie[i];

				else if (isalpha(tie[i][0]))
					cout << "," << tie[i];
				if (i == z - 1 && isalpha(tie[i][0]))
					cout << endl;

			}

		} else {
			printf("No changes\n");

		}
		printf("\n");

	}
}
