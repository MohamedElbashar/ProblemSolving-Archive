#include <iostream>
#include<stdio.h>
using namespace std;
int cnt;
int main() {
	//freopen("myfile.txt", "w", stdout);
	int t, a, b, res = 0;
	cin >> t;
	while (t--) {
		cin >> a >> b;
		for (int i = a; i <= b; i++) {
			if (i % 2 != 0) {
				res += i;
			}
		}
		cout << "Case " << ++cnt << ": " << res << endl;
		res=0;
	}
}
