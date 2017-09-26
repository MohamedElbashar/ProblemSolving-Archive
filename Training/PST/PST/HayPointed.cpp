#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <string>
#include<string.h>
#include <cassert>
#include<map>
using namespace std;
int n, m;
string s, q, s2[10001];
vector<int> y;
int cnt;
map<string, int> str;
int main() {
	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		cin >> s;
		cin >> str[s];
	}
	for (int i = 0; i < n; i++) {
		while (cin >> q && q != ".") {
			if (str[q]) {
				cnt += str[q];
			}
		}
		y.push_back(cnt);
		cnt = 0;
	}
}
