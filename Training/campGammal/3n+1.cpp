// 3n+1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;
int Math(int x)
{
	if (x == 1) return 1;
	if (x % 2 == 0)
		return 1 + Math(x / 2);
	return 1 + Math(3 * x + 1);
}

int main()
{
	int n;
	cin >> n;
	cout << Math(n);
	cout << endl;

}

