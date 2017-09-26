#include <bits/stdc++.h>
using namespace std;
char arr[10001][10001];
int main() {
	//freopen("myfile.txt", "w", stdout);
	int t, c = 0;
	cin >> t;
	char s[10001];
	getchar();
	while (t--) {
		gets(s);
		int n =strlen(s);
		double x = sqrt(n);
		if ((x - (int) x) > 0.0) {
			cout << "INVALID" << endl;
		} else {
			for (int i = 0; i < x; i++) {
				for (int j = 0; j < x; j++) {
					arr[i][j] = s[c++];
				}
			}
			for (int i = 0; i < x; i++) {
				for (int j = 0; j < x; j++) {
					cout << arr[j][i];
				}
			}
			cout << endl;
			c=0;
			//t--;

		}
	}

}
