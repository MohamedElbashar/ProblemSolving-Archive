#include <iostream>
#include<stdio.h>
using namespace std;
int c, n;
string s;
int main() {
	while (cin >> n >> s && n) {
		c = s.length() / n;
		for (int i = c; i < s.length() + c; i += c) {
			for (int j = i - 1; j >= i - c; j--) {
				cout << s[j];
			}
		}

		cout << endl;
	}
}
