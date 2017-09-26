#include <bits/stdc++.h>
using namespace std;
string s, t;
int main() {
	//freopen("myfile.txt", "w", stdout);
	while (cin >> s >> t) {
		int cnt = 0, cnt2 = 0, inx = 0, i = 0, j = 0;
		for (int i = 0; i < s.length(); i++) {
			for (int j = 0; j < t.length(); j++) {
				if (s[i] == t[j] && inx <= j) {
					inx = j;
					t[j]='.';
					cnt++;
					break;
				} else if (j == t.length() - 1) {
					goto next;

				}
			}
		}
		if (cnt == s.length()) {
			cout << "Yes" << endl;
		} else {
			next: cout << "No" << endl;
		}
	}
}
