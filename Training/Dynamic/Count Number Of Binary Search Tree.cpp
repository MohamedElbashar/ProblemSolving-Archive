#include "stdafx.h"
#include<iostream>
#include<string.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int arr[100];
	memset(arr, 0, sizeof arr);
	arr[0] = 1;
	arr[1] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			arr[i] =arr[i]+ arr[j] * arr[i - j - 1];
		}
	}
	
	cout << arr[n] << endl;
	return 0;
}

