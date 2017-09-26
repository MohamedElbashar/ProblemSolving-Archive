#include<bits/stdc++.h>
using namespace std;
int i, s, d, n, m, curr, cnt[1000];
vector<int> arr[1000];
vector<int> ans;
queue<int> ready;
int main() {
	memset(arr,0,sizeof arr);
	memset(cnt,0,sizeof cnt);
	cin>>n>>m;
	for (i = 0; i < m; i++) {
		cin>>s>>d;
		arr[s].push_back(d);
		cnt[d]++;
	}
	for (i = 1; i <= n; i++) {
		if (!cnt[i]) {
			ready.push(i);
		}
	}
	while (ready.size()) {
		curr = ready.front();
		ready.pop();
		ans.push_back(curr);
		for (i = 0; i < arr[curr].size(); i++) {
			cnt[arr[curr][i]]--;
			if (cnt[arr[curr][i]] == 0) {
				ready.push(arr[curr][i]);
			}
		}
	}
	if (ans.size() != n) {
		cout << "invalid";
	} else
		for (i = 0; i < n; i++) {
			cout << ans[i]<<" ";
		}
}
