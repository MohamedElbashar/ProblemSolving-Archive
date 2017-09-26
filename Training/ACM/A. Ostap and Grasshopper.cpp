#include <bits/stdc++.h>
using namespace std;
int n, k, i, j;
int cnt;
int flag = 0;
int main() {
	cin >> n >> k;
	char arr[101];
	for (i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (i = 0; i < n; i++) {
		if (arr[i] == 'G' || arr[i] == 'T') {
			cnt = i;
			break;
		}
	}

	for (int i = cnt + k; i < n; i = i + k) {
		if (arr[i] == '#') {
			break;
		} else if (arr[i] == '.') {
			continue;
		} else {
			flag = 1;
		}
	}
	if (flag) {
		cout << "YES \n";

	} else {
		cout << "No \n";
	}
}
