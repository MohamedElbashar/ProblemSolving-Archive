#include "stdafx.h"
#include <iostream>
#include <set>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;
int n, m, s, d, i, cur;
int cnt[10001];
vector<int> arr[1001];
vector<int> ans;
set<int> ready;
int main()
{
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
