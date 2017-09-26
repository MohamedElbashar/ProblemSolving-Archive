#include"stdafx.h"
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int main() {
	int total;
	int coin[100];
	int n;
	int arr[100][100];
	memset(arr, -1, sizeof arr);
	arr[0][0] = 0;
	cin >> total;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}
	for (int i = 0; i < n; i++) {
		if (arr[i][0] != -1)
			arr[i + 1][0] = max(arr[i][0], arr[i + 1][0]);
	}
	for (int j = 0; j <= total; j++) {
		arr[0][j] = j;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= total; j++) {
			if (j - coin[i - 1] >= 0) {
				arr[i][j] = min(arr[i][j - coin[i - 1]] + 1, arr[i - 1][j]);
			}
			else {
				arr[i][j] = arr[i - 1][j];
			}
		}
	}
	cout << arr[n][total] << endl;
	int j = total;
	int i = n;
	while (i >= 1) {
		if (arr[i][j] != arr[i - 1][j]) {
			j = j - coin[i - 1];
			cout << coin[i - 1] << " ";
		}
		else if (arr[i][j] == arr[i - 1][j]) {
			i--;
		}
		if (j == 0) {
			break;
		}
	}
	cout << endl;
}
