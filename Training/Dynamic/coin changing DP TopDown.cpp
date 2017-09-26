#include "stdafx.h"
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;

int main()
{
	int i, j;
	int n, total;
	int coins[100];
	int ordr[100];
	int arr[100];
	int curr = 0;
	memset(ordr, -1, sizeof ordr);
	cin >> n >> total;
	for (i = 0; i < n; i++) {
		cin >> coins[i];
	}
	arr[0] = 0;
	for (i = 1; i <= total; i++) {
		arr[i] = INT_MAX - n;
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j <= total; j++) {
			if (j >= coins[i]) {
				if (arr[j - coins[i]] == INT_MAX - n) {
					continue;
				}
				else {
					curr = arr[j];
					arr[j] = min(arr[j], 1 + arr[j - coins[i]]);
					if (curr != arr[j]) {
						ordr[j] = i;
					}
				}
			}
		}
	}
	int s = total;
	while(s>0){
		cout << coins[ordr[s]] << "  ";
		s = s - coins[ordr[s]];

	}
	cout << endl;
}

