#include "stdafx.h"
#include<iostream>
#include<string>
#include<string.h>
using namespace std;


int main()
{
	string pattern, str;
	cin >> str;
	cin >> pattern;
	int patleng = pattern.length();
	int strleng = str.length();
	int arr[100][100], i, j;
	memset(arr, -1, sizeof arr);
	arr[0][0] = true;
	for (i = 1; i <= strleng; i++) {
		for (j = 1; j <= patleng; j++) {
			if (pattern[j - 1] == '.' || str[i - 1] == pattern[j - 1]) {
				arr[i][j] = arr[i - 1][j - 1];
			}
			else if (pattern[j - 1] == '*') {
				arr[i][j] = arr[i][j - 2];
				if (pattern[j - 2] == '.' || pattern[j - 2] == str[i - 1]) {
					arr[i][j] = arr[i][j] || arr[i - 1][j];
				}
			}
			else {
				arr[i][j] = false;
			}
		}
	}
	if (arr[strleng][patleng] == 1) {
		cout << "true";
	}
	else {
		cout << "false";
	}
}

