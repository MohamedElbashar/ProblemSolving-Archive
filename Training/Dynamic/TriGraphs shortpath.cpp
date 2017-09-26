#include "stdafx.h"
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int a[100][3];
int main()
{
	int i = 1;
	while (1) {
		int n;
		cin >> n;
		if (n == 0)
			return 0;

		for (int i = 0; i < n; i++)
			cin >> a[i][0] >> a[i][1] >> a[i][2];
		cout << i << ". ";
		if (n == 1) {
			cout << a[0][1] << endl;
		}
		else {
			a[1][0] += a[0][1];
			a[0][2] += a[0][1];
			a[1][1] += min(min(a[1][0], a[0][1]), a[0][2]);
			a[1][2] += min(min(a[0][2], a[0][1]), a[1][1]);



			for (int i = 2; i < n; i++) {
				a[i][0] += min(a[i - 1][0], a[i - 1][1]);
				a[i][1] += min(min(min(a[i][0], a[i - 1][0]), a[i - 1][1]), a[i - 1][2]);
				a[i][2] += min(min(a[i][1], a[i - 1][1]), a[i - 1][2]);
			}
			cout << a[n - 1][1] << endl;
			i++;
		}
	}
	return 0;
}

