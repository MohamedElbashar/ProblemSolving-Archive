#include <bits/stdc++.h>
using namespace std;
int n, m, k, cnt, cnt2;
int arr[110];
vector<int> v;
int main() {
	/*freopen("out.txt", "w", stdout);
	 freopen("in.txt", "r", stdin);*/
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = m; i < n; i++) {
		cnt += 10;
		if (arr[i] <= k && arr[i]) {
			v.push_back(cnt);
		}
	}
	for (int i = m - 2; i >= 0; i--) {
		cnt2 += 10;
		if (arr[i] <= k && arr[i]) {
			v.push_back(cnt2);
		}
	}
	int mn = v[0];
	for (int i = 1; i < (int) v.size(); i++) {
		if (v[i] < mn) {
			mn = v[i];
		}
	}
	cout << mn;

}
