#include "stdafx.h"
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
int main() {
	int sum, n;
	int set[100];
	cin >> sum;
	cin >> n;
	bool arr[100][100];
	for (int i = 0; i < n; i++) {
		cin >> set[i];
	}
	for (int i = 0; i <= sum; i++) {
		arr[0][i] = false;
	}
	for (int i = 0; i <= n; i++) {
		arr[i][0] = true;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= sum; j++) {
			if (arr[i - 1][j] == true)
			{
				arr[i][j] = arr[i - 1][j];
				continue;
			}
			if (j - set[i - 1] >= 0) {
				if (j - set[i - 1] == 0 || arr[i - 1][j - set[i - 1]] == true) {
					arr[i][j] = true;
				}
				else {
					arr[i][j] = false;
				}
			}
			else
			{
				arr[i][j] = false;
			}
		}
	}
	if (arr[n][sum] == 1)
	{
		cout << "True" << endl;
	}

	else
	{
		cout << "fasle" << endl;
	}
}
