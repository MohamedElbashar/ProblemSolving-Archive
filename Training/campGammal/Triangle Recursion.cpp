// Triangle Recursion.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;


int triangle2(int y)
{
	if (y <= 0)
		return 0;
	for (int i = 0;i < y;i++)
		cout << "*";
	cout << endl;
	triangle2(y - 1);
	

}

int triangle(int x)
{
	if (x <= 0)
		return 0;
	triangle(x - 1);
	for (int i = 0;i < x;i++)
		cout << "*";
	cout << endl;
	
}

int main()
{

	int n;
	cin >> n;
	triangle(n);
	triangle2(n);
}

