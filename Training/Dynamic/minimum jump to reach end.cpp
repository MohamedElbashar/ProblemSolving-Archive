#include "stdafx.h"
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int n, i, j, arr[100], numOfJumps[100], actualJump[100], curr;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> arr[i];
		numOfJumps[i] = INT_MAX;
	}
	numOfJumps[0] = 0;
	actualJump[0] = -1;
	for (i = 1; i < n; i++) {
		for (j = 0; j < i; j++) {
			if (j + arr[j] >= i) {
				curr = numOfJumps[i];
				numOfJumps[i] = min(numOfJumps[i], numOfJumps[j] + 1);
				if (curr != numOfJumps[i]) {
					actualJump[i] = j;
				}
			}
		}
	}
	cout << "the number of jumps = " << numOfJumps[n - 1] << endl;
	int k = n - 1;
	while (k >= 0) {
		cout << arr[k]<<" ";
		k = actualJump[k];
	}
	cout << endl;
}

