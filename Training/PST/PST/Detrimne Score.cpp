#include <bits/stdc++.h>.
using namespace std;
int main() {
	int t;
	cin >> t;
	string s;
	//freopen("myfile.txt", "w", stdout);
	while (t--) {
		int cnt = 1, n = 0;
		cin >> s;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == 'O') {
				n += cnt++;
			} else {
				cnt = 1;
			}
		}
		cout << n<<endl;
	}
}
