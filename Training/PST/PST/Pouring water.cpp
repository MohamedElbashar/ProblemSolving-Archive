#include <bits/stdc++.h>
using namespace std;
int t, a, b, c, cnt = 1;
int gcd(int a, int b) {

	return b == 0 ? a : gcd(b, a % b);

}
int solve(int x, int y) {
	int ret=0, xa = 0, yb = 0;
	int n=1;
	while(n){
		if (xa == c || yb == c)
			return ret;
		if (yb == y)
			yb = 0;
		else if (xa == 0)
			xa = x;
		else {
			int ret2 = min(y - yb, xa);
			xa -= ret2;
			yb += ret2;

		}
		ret++;

	}
}
int main() {
	cin >> t;
	while (t--) {
		cin >> a >> b >> c;
		int g = gcd(a, b);  //es7aa
		if (c % g != 0 || c > max(a, b) || (c > b && c > a)) {
			cout << -1 << endl;
		} else if (a == c || b == c) {
			cout << 1 << endl;
		} else if (c == 0) {
			cout << 0 << endl;
		} else {
			int res = solve(a, b);
			res = min(solve(b, a), res); // wl3ks
			cout<<res;

		}
	}
}
