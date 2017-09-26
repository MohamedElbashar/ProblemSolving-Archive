#include <bits/stdc++.h>
using namespace std;
void solve(int a, char from, char mid, char to) {
	if (a == 1) {
		cout << "Move 1 from " << from << " to " << to << endl;
		return;
	} else {
		solve(a - 1, from, to, mid);
		cout << "Move " << a << " from " << from << " to " << to << endl;
		solve(a - 1, mid, from, to);
	}
}
int main() {
	int n;
	cin >> n;
	solve(n, 'A', 'B', 'C');
}
