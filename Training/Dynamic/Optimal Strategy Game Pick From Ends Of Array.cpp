#include "stdafx.h"
#include<iostream>
#include<algorithm>
using namespace std;
int Add(int x, int y, int cost[])
{
	int summ = 0;
	for (int i = x; i <= y; i++) {
		summ += cost[i];
	}
	return summ;
}
int main()
{

	int n, i, j, l;
	pair<int, int> arr[100][100];
	int values[100];
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> values[i];
	}
	for (l = 0; l < n; l++) {
		for (i = 0; i < n; i++) {
			j = l + i;
			if (j >= n) {
				break;
			}
			if (l == 0) {
				arr[i][j].first = values[i];
				arr[i][j].second = 0;
			}
			else {
				arr[i][j].first = max(arr[i + 1][j].second + values[i], arr[i][j - 1].second + values[j]);
				arr[i][j].second = Add(i, j, values) - arr[i][j].first;
			}
		}
	}
	cout << arr[0][n - 1].first - arr[0][n - 1].second << endl;
}

