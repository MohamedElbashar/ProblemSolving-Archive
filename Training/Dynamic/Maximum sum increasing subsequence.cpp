#include "stdafx.h"
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int main()
{
	int n, i, j;
	cin >> n;
	int curr;
	int arr[100], maxValue[100], actualSum[100];
	for (i = 0; i < n; i++) {
		cin >> arr[i];
		maxValue[i] = arr[i];
		actualSum[i] = i;
	}
	for (i = 1; i < n; i++) {
		for (j = 0; j < i; j++) {
			curr = maxValue[i];
			if (arr[j] < arr[i]) {
				maxValue[i] = max(maxValue[i], maxValue[j] + arr[i]);
			}
			if (curr != maxValue[i]) {
				actualSum[i] = j;
			}
		}
	}
	int mx = 0;
	int cnt = 0;
	for (i = 0; i < n; i++) {
		if (mx < maxValue[i]) {
			mx = maxValue[i];
			cnt = i;
		}
	}
	cout << mx << endl;
	while (cnt >= 0) {
		
		if (cnt != 0) {
			cout << arr[cnt] << " ";
			cnt = actualSum[cnt];
		}

		else{
			cout << arr[cnt];
			break;
		}
	}
	cout << endl;
}

