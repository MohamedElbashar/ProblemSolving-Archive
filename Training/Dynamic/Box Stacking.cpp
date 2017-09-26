#include"stdafx.h"
#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

struct box
{
	int L, W, H;
};
int arr[100][4];
int n;
box res[100];
int mxa[100];
int boxes[100];

int main()
{
	cin >> n;
	for (int i = 0; i < n && cin >> res[i].L >> res[i].W >> res[i].H; i++) {}
	int cnt = 0;

	for (int i = 0; i < n; i++) {
		//First rotation
		arr[cnt][0] = max(res[i].L, res[i].W);
		arr[cnt][1] = min(res[i].L, res[i].W);
		arr[cnt][2] = res[i].H;
		boxes[cnt] = cnt;
		arr[cnt][3] = arr[cnt][0] * arr[cnt][1];
		cnt++;

		//second rotation
		arr[cnt][0] = max(res[i].L, res[i].H);
		arr[cnt][1] = min(res[i].L, res[i].H);
		arr[cnt][2] = res[i].W;
		boxes[cnt] = cnt;
		arr[cnt][3] = arr[cnt][0] * arr[cnt][1];
		cnt++;

		//third rotation
		arr[cnt][0] = max(res[i].W, res[i].H);
		arr[cnt][1] = min(res[i].W, res[i].H);
		arr[cnt][2] = res[i].L;
		boxes[cnt] = cnt;
		arr[cnt][3] = arr[cnt][0] * arr[cnt][1];
		cnt++;

	}


	for (int i = 0; i < 3 * n; i++) {

		for (int j = 0; j < 3 * n - 1; j++) {

			if (arr[j][3] < arr[j + 1][3]) {

				swap(arr[j][3], arr[j + 1][3]);

				swap(arr[j][2], arr[j + 1][2]);

				swap(arr[j][1], arr[j + 1][1]);

				swap(arr[j][0], arr[j + 1][0]);

			}
		}
	}


	for (int i = 0; i < 3 * n; i++) {
		mxa[i] = arr[i][2];
	}

	int i = 1;
	int j = 0;

	while (i < 3 * n) {
		if (j < i) {
			if (arr[j][0] > arr[i][0] && arr[j][1] > arr[i][1]) {
				if (mxa[j] + arr[i][2] > mxa[i]) {
					mxa[i] = mxa[j] + arr[i][2];
					boxes[i] = j;
				}
				j++;
			}
			else {
				j++;
			}

		}
		else {
			j = 0;
			i++;
		}
	}

	int ret = 0;
	int ret1 = 0;
	int num;
	for (int s = 0; s < 3 * n; s++) {
		if (ret < mxa[s])
			ret = mxa[s];
		if (ret1 < boxes[s]) {
			ret1 = boxes[s];
			num = s;
		}
	}
	cout << ret << endl;
	int q = num;
	while (q >= 0) {

		cout << arr[q][0] << " " << arr[q][1] << " " << arr[q][2] << endl;
		q = boxes[q];
		if (q == 0) {
			cout << arr[q][0] << " " << arr[q][1] << " " << arr[q][2] << endl;
			break;
		}
		continue;

	}
}
