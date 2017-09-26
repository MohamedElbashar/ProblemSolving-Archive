#include "stdafx.h"
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
bool cmp(pair<int, int>b, pair<int, int>a)
{
	if (b.second > a.second)
		return 0;
	return 1;
}
int main()
{
	int n;
	int jobs[100];
	int arr[100];
	cin >> n;
	pair<int, int> sd[100];
	for (int i = 0; i < n; i++) {
		cin >> jobs[i];
	}
	for (int i = 0; i<n&&cin >> sd[i].first >> sd[i].second; i++) {}
	sort(sd, sd + n, cmp);

	for (int i = 0; i < n; i++) {
		arr[i] = jobs[i];
	}
	int i = 1;
	int j = 0;

	while (j <= i) {
		if (i == n) {
			break;
		}
		if (sd[j].second <= sd[i].first) {
			arr[i] = max(arr[i], jobs[i] + arr[j]);
			j++;
		}

		else {
			i++;
			j = 0;
		}
	}
	int mx = 0;
	for (int m = 0; m < n; m++) {
		if (arr[m] > mx) {
			mx = arr[m];
		}
	}
	cout << mx << endl;
}

