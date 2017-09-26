#include<bits/stdc++.h>
using namespace std;
string s;
int main() {
	while (getline(cin, s)) {
		stringstream iss(s);
		string m;
		while (iss >> m) {
			for (int i = m.length() - 1; i >= 0; i--) {
				cout << m[i];
			}
			cout << " ";
		}
		cout << endl;
	}
}
