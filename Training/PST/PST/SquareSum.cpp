#include <iostream>
#include <stdio.h>
using namespace std;
int arr[11][11];
int cnt;
int main() {
	int n;
	freopen("myfile.txt", "w", stdout);
	while (cin >> n && n) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
			}
		}
		cout << "Case " << ++cnt << ":";
		int x = 0;
		int res = 0;
		(n % 2 == 0) ? x = n / 2 : x = (n / 2) + 1;
		for (int l = 0; l < x; l++) {
			for (int i = l; i < n - l; i++) {
				if (i == l || i == n - l - 1) {
					for (int j = l; j < n - l; j++) {
						res += arr[i][j];
					}
				} else if (i > l && i != n - l) {
					res += (arr[i][l] + arr[i][n - l - 1]);
				}
			}
			cout <<" "<< res ;
			res = 0;
		}
		cout << endl;
	}
}
