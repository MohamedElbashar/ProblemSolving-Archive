#include <bits/stdc++.h>
using namespace std;
int n, m, s, d, i, cur;
long int cnt[1000001];
vector<long int> arr[1000001];
vector<int> ans;
set<int> ready;
int main()
{
	memset(cnt,0,sizeof cnt);
	memset(arr,0,sizeof arr);
	scanf("%d %d", &n, &m);
	for (i = 0; i < m; i++) {
		scanf("%d %d", &s, &d);
		arr[s].push_back(d);
		cnt[d]++;
	}
	for (i = 1; i <=n; i++) {
		if (!cnt[i])
			ready.insert(i);
	}

	while (ready.size()) {
		cur = *ready.begin();
		ready.erase(ready.begin());
		ans.push_back(cur);
		for (i = 0; i<arr[cur].size(); i++) {
			cnt[arr[cur][i]]--;
			if (cnt[arr[cur][i]] == 0) {
				ready.insert(arr[cur][i]);
			}
		}
	}
	if (ans.size() != n)
		cout << "sandro fails.";
	else {
		for (i = 0; i<n; i++) {
			printf("%d ", &ans[i]);
		}
	}
	cout << endl;
}
