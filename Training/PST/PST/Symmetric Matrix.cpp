#include <bits/stdc++.h>
using namespace std;
long long arr[101][101];
int n, t, c;
int main() {
	cin >> t;
	//freopen("myfile.txt", "w", stdout);
	while (t--) {
		char ch[10];
		getchar();
		gets(ch);
		sscanf(ch, "%c = %d", &ch[0], &n);
		int flag = 1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
				if (arr[i][j] < 0) {
					flag = 0;
				}
			}
		}
		cout << "Test #" << ++c << ": ";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!flag) {
					cout << "Non-symmetric." << endl;
					break;
				}
				if (arr[i][j] != arr[n - 1 - i][n - 1 - j]) {
					cout << "Non-symmetric." << endl;
					flag = 0;
					break;
				}
			}
			if (!flag) {
				break;
			}
		}
		if (flag) {
			cout << "Symmetric." << endl;
		}
	}
}
