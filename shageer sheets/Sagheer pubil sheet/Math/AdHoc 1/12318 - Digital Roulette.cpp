#include <bits/stdc++.h>
using namespace std;
int n, m, k, a[11];
set<long long int> st;
long long int solve(int x) {
	long long int ans = 0, pow = 1;
	for (int i = 0; i <= k; i++) {
		if (a[i])
			ans = (ans + a[i] * pow) % (n + 1);
		pow = (pow * x) % (n + 1);
	}
	return ans;
}
int main() {
	//file();
	while (scanf("%d%d", &n, &m) && n && m) {
		scanf("%d", &k);
		for (int i = 0; i <= k; i++)
			scanf("%d", &a[i]);
		for (int i = 0; i <= m; i++)
			st.insert(solve(i));
		printf("%d\n", (int) st.size());
		st.clear();
	}
}
