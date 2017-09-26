#include "stdafx.h"
#include<iostream>
using namespace std;

int main()
{
	int n, A[100], B[100];
	cin >> n;
	A[0] = 1;
	B[0] = 1;
	for (int i = 1; i < n; i++) {
		A[i] = B[i - 1] + A[i - 1];
		B[i] = A[i - 1];
	}
	cout << A[n - 1] + B[n - 1] << endl;
    return 0;
}

