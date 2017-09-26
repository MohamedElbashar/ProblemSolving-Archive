#include <bits/stdc++.h>
using namespace std;
int main() {
	int T, N;
	cin >> T;
	getchar();
	char ch[20];
	gets(ch);
	while (T--) {
		int a;
		vector<int> Tab;
		while (gets(ch) && strlen(ch)) {
			Tab.push_back(atoi(ch));
		}
		int MaxLIS = 1;
		int DP[Tab.size()];
		int Path[Tab.size()];
		for (int i = 0; i < Tab.size(); i++) {
			Path[i] = i;
		}
		memset(DP, 0, Tab.size() * sizeof(int));
		DP[0] = 1;
		for (int i = 1; i < Tab.size(); i++) {
			DP[i] = 1;
			for (int j = 0; j < i; j++) {
				if (Tab[j] < Tab[i]) {
					if ((1 + DP[j]) > DP[i]) {
						DP[i] = 1 + DP[j];
						Path[i] = j;
					}
				}
			}
		}
		int idx = distance(DP, max_element(DP, DP + Tab.size()));
		cout << "Max hits: " << DP[idx] << endl;
		vector<int> Solution;
		while (Path[idx] != idx) {
			Solution.push_back(Tab[idx]);
			idx = Path[idx];
		}
		Solution.push_back(Tab[idx]);
		for (int i = Solution.size() - 1; i >= 0; i--) {
			cout << Solution[i] << endl;
		}
		if (T != 0)
			cout << endl;
	}
	return 0;
}
