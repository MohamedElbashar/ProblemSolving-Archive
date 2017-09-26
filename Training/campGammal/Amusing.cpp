#include "stdafx.h"
#include<iostream>
#include <string>
#include<string.h>
#include<algorithm>
using namespace std;
long long int k;

string res[100000];

int main()
{
	int NumOfCases;
	cin >> NumOfCases;
	for (int j = 0; j < NumOfCases; j++)
	{
		int dig = 1;
		cin >> k;
		while (k > pow(2, dig))
		{
			k -= pow(2, dig);
			dig++;
		}

		for (int i = dig - 1 ;i >= 0;i--)
		{
			if (k > pow(2, i))
			{
				res[j].append("6");
				k -= pow(2, i);
			}
			else
			{
				res[j].append("5");
			}
		}
	}
	for (int i = 0; i < NumOfCases; i++)
	{
		cout << res[i] << endl;
	}



}
