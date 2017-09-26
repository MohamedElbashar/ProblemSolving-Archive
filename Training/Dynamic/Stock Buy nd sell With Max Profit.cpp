#include"stdafx.h"
#include <stdio.h>
#include<iostream>
#include<algorithm>

using namespace std;

int mx;
int cn;
int n, i, j, trans, m, curr;
int price[1001];
int s;
int arr[1001][1001];

int main()

{
	int tstcase;
	scanf(" %d", tstcase);
	for (int q = 0; q < tstcase; q++) {
		scanf(" %d", trans); 
		scanf(" %d", n);


		for (i = 0; i < n; i++) {

			cin >> price[i];
		}

		for (i = 0; i < n; i++) {

			if (mx < price[i]) {
				mx = price[i];
				cn = i;
			}
		}

		if (cn == 0) {

			cout << 0 << endl;

			return 0;
		}
		arr[0][0] = 0;

		for (i = 1; i <= n; i++) {

			arr[0][i] = 0;
		}

		for (i = 1; i <= trans; i++) {

			arr[i][0] = 0;
		}

		for (i = 1; i <= trans; i++) {

			for (j = 1; j < n; j++) {

				for (m = 0; m < j; m++) {

					curr = max(arr[i][j - 1], price[j] - price[m] + arr[i - 1][m]);

					if (curr > arr[i][j]) {

						arr[i][j] = curr;
					}
				}
			}
		}
		printf(" %d", arr[trans][n - 1]);
	}
}



