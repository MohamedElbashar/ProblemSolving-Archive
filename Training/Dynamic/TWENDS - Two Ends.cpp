#include "stdafx.h"
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
long int nums[1001];
pair<long int, long int >arr[1001][1001];
int sum(int x, int y, long  int a[])
{
	long int res = 0;
	for (int i = x; i <= y; i++) {
		res += a[i];
	}
	return res;
}
int main()
{
	int n;
	cin >> n;
	int counter = 0;
	while (n) {

		counter++;
		if (n == 0 || n % 2 != 0) {
			return 0;
		}
		if (sum(0, n - 1, nums) > 1e6) {
			return 0;
		}
		for (int i = 0; i < n; i++) {
			cin >> nums[i];
		}
		for (int l = 0; l < n; l++) {
			for (int i = 0; i < n; i++) {
				int j = i + l;
				if (j >= n) {
					break;
				}
				else {
					if (l == 0) {
						arr[i][j].first = nums[i];
						arr[i][j].second = 0;
					}
					else {
						arr[i][j].first = max(arr[i + 1][j].second + nums[i], arr[i][j - 1].second + nums[j]);
						arr[i][j].second = sum(i, j, nums) - arr[i][j].first;
					}
				}
			}
		}
		cout << "in game " << counter << ", the gready might lose by as many as " << arr[0][n - 1].first - arr[0][n - 1].second << " points." << endl;
		cin >> n;
	}
}

