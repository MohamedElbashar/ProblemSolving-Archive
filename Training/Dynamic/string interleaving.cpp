#include "stdafx.h"
#include<iostream>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;

int main()
{
	string A, B, test;
	cin >> A;
	cin >> B;
	cin >> test;
	int i, j, k;
	bool arr[100][100];
	memset(arr, true, sizeof arr);
	arr[0][0] = true;
	if (test.length() != A.length() + B.length()) {
		cout << "No"<<endl;
		return 0;
	}
	for (i = 1; i <= A.length(); i++) {
		if (A[i - 1] == test[i - 1]) {
			arr[0][i] = true;
		}
		else {
			arr[0][i] = false;
		}
	}
	for (i = 1; i <= B.length(); i++) {
		if (B[i - 1] == test[i - 1]) {
			arr[i][0] = true;
		}
		else {
			arr[i][0] = false;
		}
	}
	for (i = 1; i <= B.length(); i++) {
		for (j = 1; j <= A.length(); j++) {
			if (test[i + j - 1] == A[j - 1] && arr[i][j - 1] == true) {
				arr[i][j] = true;
			}
			else if (test[i + j - 1] == B[i - 1] && arr[i - 1][j] == true) {
				arr[i][j] = true;
			}
			else {
				arr[i][j] = false;
			}
		}
	}
	if (arr[B.length()][A.length()] == true) {
		cout << "YES"<<endl;
	}
	else {
		cout << "NO"<<endl;
	}

}
