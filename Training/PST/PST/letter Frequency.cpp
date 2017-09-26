#include <bits/stdc++.h>
using namespace std;
vector<pair<char, int> > arr;
char s[201];

int cmp(pair<char, int>&a, pair<char, int>&b) {
	if (a.second == b.second)
		return a.first < b.first;
	else {
		return a.second > b.second;
	}
	//return (a.second == b.second) ? a.first < b.first : a.second > b.second;

}
int main() {
	int flag = 0;
	int t;
	cin >> t;
	while (t > 0) {
		freopen("myfile.txt", "w", stdout);
		getchar();
		gets(s);
		for (int i = 0; i < strlen(s); i++) {
			flag = 0;
			if (!isalpha(s[i])) {
				continue;
			}
			if (isalpha(s[i]) && isupper(s[i])) {
				s[i] = tolower(s[i]);
			}
			for (int j = 0; j < arr.size(); j++) {

				if (s[i] == arr[j].first && s[i] != ' ') {
					arr[j].second++;
					flag = 1;
					break;
				}

			}
			if (!flag && s[i] != ' ') {
				arr.push_back(make_pair(s[i], 1));
			}
		}
		sort(arr.begin(), arr.end(), cmp);
		cout << arr[0].first;
		for (int i = 1; i < arr.size(); i++) {
			if (arr[i].second == arr[0].second) {
				cout << arr[i].first;
			}
		}
		cout << endl;
		arr.clear();
		t--;
	}
}
