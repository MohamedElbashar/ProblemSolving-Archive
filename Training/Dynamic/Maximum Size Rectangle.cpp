#include "stdafx.h"
#include<iostream>
#include<algorithm>
using namespace std;
int x, y;
int res[1000][1000];
int arr[1000];
int test[1000];
int ret;
int ret2;
int cnut = 0;
int maxe;

int main()
{
	cin >> x >> y;
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			cin >> res[i][j];
		}
	}
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			if (res[i][j] == 0) {
				arr[j] = 0;
			}
			else {
				arr[j] += res[i][j];
			}
			test[j] = arr[j];
		}
		int mn;
		for (int q = 0; q < y; q++) {
			cnut = 0;
			for (int g = 0; g < y; g++) {
				if (test[g] == 0) {
					continue;
				}
				else {
					mn = test[g];
					break;
				}
			}

			for (int k = 0; k < y; k++) {

				if (mn >= test[k] && test[k] != 0) {
					mn = test[k];
				}
			}
			for (int r = 0; r < y; r++) {
				if (test[r + 1] == 0) {
					continue;
				}
				if (test[r] >= mn) {
					ret += mn;
				}
			}
			ret2 = ret + mn;
			maxe = max(maxe, ret2);
			ret = 0;
			ret2 = 0;
			for (int v = 0; v < y; v++) {
				if (test[v] == mn) {
					test[v] = 0;
				}
				if (test[v] == 0) {
					cnut++;
				}
			}
			if (cnut == y) {
				break;
			}
		}
	}
	cout << maxe << endl;
}

