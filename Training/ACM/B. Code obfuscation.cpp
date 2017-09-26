#include<bits/stdc++.h>
using namespace std;
long long  k, a, b, n, cnt, t, q;
int main() {
	cin >> k >> a >> b;
	if (a > b) {
		n = a;
	} else {
		n = b;
	}
	if(a+b==0){
		cout << -1;
		return 0;
	}
	if (n < k) {
		cout << -1;
		return 0;
	} else {
		min(a, b) < k ? cout << max(a, b) / k : cout << (a + b) / k;
	}
}
