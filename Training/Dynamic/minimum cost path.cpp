#include "stdafx.h"
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int nums[100][100];
	int arr[100][100];
	int r, c, i, j;
	cin >> r >> c;
	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++) {
			cin >> nums[i][j];
		}
	}
	arr[0][0] = nums[0][0];
	for (i = 1; i < c; i++) {
		arr[0][i] = arr[0][i - 1] + nums[0][i];
	}
	for (j = 1; j < r; j++) {
		arr[j][0] = arr[j - 1][0] + nums[j][0];
	}
	for (i = 1; i < r; i++) {
		for (j = 1; j < c; j++) {
			arr[i][j] = min(arr[i - 1][j], arr[i][j - 1]) + nums[i][j];
		}
	}
	cout << arr[r - 1][j - 1] << endl;
}

