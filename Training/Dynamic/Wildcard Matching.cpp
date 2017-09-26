#include "stdafx.h"
#include<iostream>
#include<string>
#include<string.h>
using namespace std;

int main()
{
	string str, pattern;
	cin >> str;
	cin >> pattern;
	bool arr[100][100];
	memset(arr, false, sizeof arr);
	arr[0][0] = true;
	int patLeng = pattern.length();
	int i, j, strLeng = str.length();

	for (i = 1; i <= patLeng; i++) {
		if (pattern[i - 1] == '*') {
			arr[0][i] = arr[0][i - 1];
		}
	}
	for (i = 1; i <= strLeng; i++) {
		for (j = 1; j <= patLeng; j++) {
			if (pattern[j - 1] == '?' || str[i - 1] == pattern[j - 1]) {
				arr[i][j] = arr[i - 1][j - 1];
			}
			else if (pattern[j - 1] == '*') {
				arr[i][j] = arr[i][j - 1] || arr[i - 1][j];
			
			}
			else {
				arr[i][j] = false;
			}
		}
	}
	bool res = arr[strLeng][patLeng];
	if (res == 1) {
		cout << "true" << endl;
	}
	else {
		cout << "false" << endl;
	}
}


