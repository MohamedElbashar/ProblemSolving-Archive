#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	char inputString[100];
	int l, r, length = 0;
	cout << "Enter a string for palindrome check\n";
	cin >> inputString;
	while (inputString[length] != '\0')
		length++;
	l = 0;
	r = length - 1;
	while (l < r) {
		if (inputString[l] != inputString[r]) {
			cout << "Not a Palindrome" << endl;
			return 0;
		}
		l++;
		r--;
	}
	cout << "Palindrome\n" << endl;

	return 0;
}
