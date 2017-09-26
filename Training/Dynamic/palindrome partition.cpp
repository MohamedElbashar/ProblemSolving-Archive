#include "stdafx.h"
#include<iostream>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;

bool solve(string B, int x, int y)
{
	int r = x;
	int c = y;
	int flag;
	while (r < c) {
		flag = -1;
		if (B[r] != B[c]) {
			flag = 1;
			break;
		}
		else {
			flag = 0;
		}
		r++;
		c--;
	}
	if (flag == 0) {
		return 0;
	}
	else {
		return 1;
	}
}
int main()
{
	string A;
	cin >> A;
	int arr[100][100];
	int i, j, l, k;
	memset(arr, -1, sizeof arr);
	for (i = 0; i < A.length(); i++) {
		j = i;
		arr[i][j] = 0;
	}
	for (l = 1; l < A.length(); l++) {
		for (i = 0; i < A.length() - 1; i++) {
			j = i + l;
			if (j > A.length() - 1) {
				break;
			}
			arr[i][j] = INT_MAX;
			bool res = solve(A, i, j);
			if (res == false) {
				arr[i][j] = 0;
			}
			else {
				for (k = i; k < j; k++) {


					arr[i][j] = min(arr[i][j], 1 + arr[i][k] + arr[k + 1][j]);
				}
			}
		}

	}
	cout << arr[0][A.length() - 1] << endl;
}

