#include "stdafx.h"
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int arr[100][100];
int res[100];
int n, m;
int curSum;
int MaxSum;
int mLeft;
int mRight;
int mUp;
int mDown;
int ret1, ret2;
int x = 0, y = 0;

int main()
{

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	memset(res, 0, sizeof res);



	int i = 0;
	int j = 0;
	while (i < m) {
		for (j = i; j < m; j++) {
			for (int k = i; k < n; k++) {
				res[k] += arr[k][j];
			}

			ret1 = ret2 = res[0];
			for (int s = 1; s <= n - 1; s++) {
				if (res[s] > ret1 + res[s]) {
					ret1 = res[s];
					x++;
				}
				else {
					ret1 = ret1 + res[s];
				}
				if (ret1 > ret2) {

					y = ret1 - ret2;
					for (int q = s; q < n; q++) {
						if (y == res[q])
							y = s;
					}
					ret2 = ret1;
				}
			}
			curSum = ret2;
			if (curSum > MaxSum) {
				MaxSum = curSum;
				mUp = x;
				mDown = y;
				mLeft = i;
				mRight = j;
			}


		}
		i++;
		j = i;
		memset(res, 0, sizeof res);
	}

	cout << MaxSum << " " << mLeft << " " << mRight << " " << mUp << " " << mDown << endl;


	for (int i = mUp; i <= mDown; i++) {
		for (int j = mLeft; j <= mRight; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

