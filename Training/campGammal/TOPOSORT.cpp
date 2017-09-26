#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;
int R, C;
vector<int>rel[1000001];
int cnt[10000001];
vector<int>ans;
set<int>myQ;
int main()
{
	int num, ral, cur;
	cin >> R >> C;
	for (int i = 0; i < C; i++) {
		cin >> num >> ral;
		rel[num].push_back(ral);
		cnt[ral]++;
	}
	for (int i = 0; i < C; i++) {
		if (!cnt[i]) {
			myQ.insert(i);
		}
	}
	while (myQ.size()) {
		cur = *myQ.begin();
		myQ.erase(myQ.begin());
		ans.push_back(cur);
	}
	for (int i = 0; i <(int) rel[cur].size(); i++) {
		cnt[rel[cur][i]]--;
		if (cnt[rel[cur][i]] == 0) {
			myQ.insert(rel[cur][i]);
		}
	}
	if (ans.size() != 0) {
		cout << "sandro fail.";
	}
	else {
		for (int i = 0; i < R; i++) {
			cout << ans[i];
		}
	}

}


