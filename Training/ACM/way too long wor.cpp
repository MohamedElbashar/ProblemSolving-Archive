#include<bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b)
{
	long long  c;
	while (a != 0) {
		c = a; a = b%a;  b = c;
	}
	return b;
}
int gcd(int x, int y) {
	if (y == 0)
		return x;

	return gcd(y, x % y);
}
int lcm(int a, int b) {
	return a * b / gcd(a, b);
}
int main()

{
	int step, mod, m;

	while (cin >> step >> mod) {
		m = gcd(step, mod);

		cout << setw(10) << step << setw(10) << mod << "    ";
		if (m == 1)
			cout << "Good Choice" << endl;
		else
			cout << "Bad Choice" << endl;
		cout << endl;
	}

	return 0;
}

