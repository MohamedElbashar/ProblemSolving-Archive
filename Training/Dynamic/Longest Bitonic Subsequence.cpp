#include "stdafx.h"
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int n, j, i;
	cin >> n;
	int arr[100], arr1[100], arr2[100], res[100];
	for (i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (i = 0; i < n; i++) {
		arr1[i] = 1;
		arr2[i] = 1;
	}
	for (i = 1; i < n; i++) {
		for (j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				arr1[i] = max(arr1[i], arr1[j] + 1);
			}
		}
	}
	for (i = n-2; i >=0; i--) {
		for (j = n-1; j > i; j--) {
			if (arr[i] > arr[j]) {
				arr2[i] = max(arr2[i], arr2[j] + 1);
			}
		}
	}
	
	for (i = 0; i < n; i++) {
		res[i] = arr1[i] + arr2[i] - 1;
	}
	int mx = 0;
	for (i = 0; i < n; i++) {
		if (res[i] > mx) {
			mx = res[i];
		}
	}
	cout << mx << endl;
	return 0;
}

