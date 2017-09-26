#include <bits/stdc++.h>
using namespace std;

int n,cnt;
vector<char> vn, vp, vs;
int main() {
	string s;
	int t;
	cin >> t;
	//freopen("myfile.txt", "w", stdout);
	while (t--) {
		cin>>s;
		for (int i = 0; i < s.length(); i++) {
			if (isalpha(s[i])) {
				vs.push_back(s[i]);
			} else if (s[i] - '0' >= 0 && s[i] - '0' < 10) {
				vn.push_back(s[i]);
				for (int j = i + 1; j < s.length(); j++) {
					if (s[j] - '0' >= 0 && s[j] - '0' < 10)
						vn.push_back(s[j]);
					else {
						break;
					}
				}
				for (int j = 0; j < vn.size(); j++) {
					n *= 10;
					n += (vn[j] - '0');
				}
				for (int j = 0; j < n; j++) {
					for (int k = 0; k < vs.size(); k++) {
						vp.push_back(vs[k]);
					}
				}
				vs.clear();
				vn.clear();
				n = 0;
			}
		}
		cout << "Case " << ++cnt << ": ";
		for (int i = 0; i < vp.size(); i++) {
			cout << vp[i];
		}
		vp.clear();
		cout << endl;
	}

}
