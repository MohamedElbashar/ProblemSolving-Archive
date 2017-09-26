#include "stdafx.h"
#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
#include<string.h>
using namespace std;

int main()
{
	int width, n;
	int res = 0;
	cin >> n >> width;
	string word[100];
	int arr[100][100];
	int spaces[100];
	int ret;
	int ntr = 0;
	int test[100];
	int cnt[100];
	int omg1 = 0, omg2 = 0;
	int kji = 0;
	int	mn = 0;
	memset(arr, -1, sizeof arr);
	for (int i = 0; i < n; i++) {
		cin >> word[i];
		spaces[i] = width - word[i].length();
	}
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			res = res + (word[j].length() + ntr);
			ntr++;
			if (i == j) {
				arr[i][j] = pow(spaces[j], 2);
			}
			else if (res <= 10) {
				ret = width - res;
				arr[i][j] = pow(ret, 2);
			}
			else {
				break;
			}
		}
		res = 0;
		ntr = 0;
	}
	int i = n - 1;
	int j = n - 1;
	while (i >= 0) {

		if (i == n - 1 && j == n - 1) {
			test[i] = arr[i][j];
			cnt[i] = n;
			i--;
			continue;
		}
		if (arr[i][j] != -1) {
			test[i] = arr[i][j];
			cnt[i] = cnt[i + 1];
			i--;
			continue;
		}
		else {
			while (j >= 0) {
				if (i == j) {
					i--;
					j = n - 1;
					break;
				}
				omg2 = omg1;
				omg1 = arr[i][j - 1] + test[j];
				kji = omg1;
				test[i] = min(kji, omg2);
				if (test[i] < omg2) {
					cnt[i] = j;
				}
				j--;
			}
		}

	}

	cout << test[0] << endl;
}

