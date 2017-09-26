#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int main() {
	int n;
	int arr[20];
	cin >> n;
	int cnt[20];
	for (int s = 0; s < n; s++) {
		cin >> arr[s];
	}
	for (int h = 0; h < n; h++) {
		cnt[h] = 1;
	}
	int i = 1;
	int j = 0;
	while (i < n) {
		while (j < n) {
			if (arr[i] > arr[j]) {
				cnt[i] = max(cnt[j] + 1, cnt[i]);
				j++;
			}
			else if (i == j) {
				i++;
				j = 0;
				continue;
			}
			else {
				j++;
				continue;
			}
		}
	}
	int max = 0;
	for (int k = 0; k < n; k++) {
		if (cnt[k] > max) {
			max = cnt[k];
		}
	}
	cout << max << endl;
}
