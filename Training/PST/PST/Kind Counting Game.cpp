#include<bits/stdc++.h>
using namespace std;
int main() {
	int t, m, i, j, flag;
	string s;
	cin >> t;
	while (t--) {
		getline(cin, s);
		m = s.length();
		for (i = 1; i < m + 1; i++) {
			flag = 1;
			for (j = 0; j < m; j++)
				if (s[j] != s[(j + i) % m]) {
					flag = 0;
					break;
				}
			if (flag) {
				cout << i << endl;
				break;
			}
		}
		if (t)
			cout << endl;
		t--;
	}
	return 0;
}
