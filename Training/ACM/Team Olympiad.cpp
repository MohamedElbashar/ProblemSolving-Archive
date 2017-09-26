#include <bits/stdc++.h>
using namespace std;
int n, arr[5001];
int arr2[5001][3];
int cnt;
int t1, t2, t3;
int flag;
int main() {
	cin >> n;

	for (int i = 0; i < n && cin >> arr[i]; i++)
		;
	int res = n / 3;

	for (int i = 0; i < res; i++) {
		for (int k = 0; k < n; k++) {
			if (arr[k] == 1) {
				t1 = k + 1;
				arr[k] = -1;
				break;
			}
		}
		for (int y = 0; y < n; y++) {
			if (arr[y] == 2) {
				t2 = y + 1;
				arr[y] = -1;
				break;
			}
		}
		for (int q = 0; q < n; q++) {
			if (arr[q] == 3) {
				t3 = q + 1;
				arr[q] = -1;
				break;
			}
		}
		if (t1 != 0 && t2 != 0 && t3 != 0) {
			cnt++;
			flag = 1;
			arr2[i][0] = t1;
			arr2[i][1] = t2;
			arr2[i][2] = t3;
			t1 = 0;
			t2 = 0;
			t3 = 0;
		} else if (!cnt) {
			flag = 0;
			break;
		}
	}
	if (flag) {
		cout << cnt << endl;
		for (int i = 0; i < cnt; i++) {
			for (int j = 0; j < 3; j++) {
				cout << arr2[i][j] << " ";
			}
			cout << endl;
		}
	} else {
		cout << 0;
	}
}
