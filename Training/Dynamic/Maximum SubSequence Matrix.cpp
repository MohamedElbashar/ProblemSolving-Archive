#include "stdafx.h"
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int r, c, i, j;
	cin >> r >> c;
	int matrix[100][100];
	int arr[100][100];
	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++) {
			cin >> matrix[i][j];
		}
	}
	for (j = 0; j <= r; j++) {
		arr[j][0] = 0;
	}
	for (i = 0; i <= c; i++) {
		arr[0][i] = 0;
	}
	for (i = 1; i <= r; i++) {
		for (j = 1; j <= c; j++) {
			if (matrix[i - 1][j - 1] == 0) {
				arr[i][j] = 0;
			}
			else {
				int mn = arr[i][j - 1];
				arr[i][j] = min(arr[i - 1][j], arr[i - 1][j - 1]);
				arr[i][j] = min(arr[i][j], mn) + 1;
			}
		}
	}
	int mx = 0;
	int s = 0;
	for (i = 0; i <= r; i++) {
		for (j = 0; j <= c; j++) {
			if (arr[i][j] > mx) {
				mx = arr[i][j];
			}

		}
	}
	for (i = 0; i <= r; i++) {
		for (j = 0; j <= c; j++) {
			if (arr[i][j] == mx) {
				s++;
			}
		}
	}
	cout <<"the Length of Square = "<< mx << endl <<"the Number of squares = "<< s << endl;
}

