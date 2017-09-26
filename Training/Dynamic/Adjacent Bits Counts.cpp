#include "stdafx.h"
#include<iostream>
#include<string.h>
using namespace std;
long long  arr[110][110][2];
int main()
{
	int t, ind, n, k, i, j, b;
	long long  ans;
	cin >> t;
	while (t--) {
		cin >> ind >> n >> k;
		memset(arr, 0, sizeof arr);

		arr[1][0][0] = arr[1][0][1] = 1;
		for (i = 2; i <= n; i++) {
			for (j = 0; j <= k; j++) {

				arr[i][j][0] = arr[i - 1][j][0] + arr[i - 1][j][1];
				if (j > 0)
					arr[i][j][1] = arr[i - 1][j - 1][1];
				arr[i][j][1] += arr[i - 1][j][0];

			}
		}
		ans = arr[n][k][0] + arr[n][k][1];
		cout << ind << " " << ans << endl;
	}

}
