#include <bits/stdc++.h>
using namespace std;
int n, q, t, mid, arr[100001], cnt;
/*int solve(int a[], int tar) {
 int s = 0, e = n - 1, t = 1;
 while (s <= e) {
 mid = (s + e) / 2;
 if (s == e) {
 while (t) {
 if (arr[mid] > tar) {
 mid--;
 } else if (arr[mid] <= tar) {
 t = 0;
 return mid;
 }
 }
 }
 if (arr[mid] > tar)
 e = mid;
 else if (arr[mid] < tar) {
 s = mid + 1;
 } else if (arr[mid] == tar) {
 return mid;
 }
 }
 }*/
int main() {
	freopen("out.txt", "w", stdout);
	 freopen("in.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + n);
	scanf("%d", &q);
	while (q--) {
		scanf("%d", &t);
		if (t >= arr[n - 1]) {
			printf("%d\n", n);
		} else if (t < arr[0]) {
			printf("%d\n", 0);
		} else {
			int s = 0, e = n - 1, mid;
			while (s <= e) {
				mid = (s + e) / 2;
				if (t < arr[mid]) {
					e = mid - 1;
				} else {
					s = mid + 1;
				}
			}
			if (t >= arr[mid])
				printf("%d\n", mid + 1);
			else
				printf("%d\n", mid);
		}
	}
}

