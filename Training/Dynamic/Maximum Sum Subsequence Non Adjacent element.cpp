#include "stdafx.h"
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n, arr[100], i, curr, incl, excl;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> arr[i];
	}
	incl = arr[0];
	excl = 0;
	for (i = 1; i < n; i++) {
		curr = incl;
		incl = max(incl, excl + arr[i]);
		excl = curr;
	}
	cout << incl << "  " << excl << endl;
	return 0;
}

