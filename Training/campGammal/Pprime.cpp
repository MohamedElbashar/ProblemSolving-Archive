#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<cstdio>
#include<stdint.h>
#include<typeinfo>
#include<vector>
#include<set>
int a, b;
int Num[100000001];
int arr[] = { 1,2,3,5,7,9 };
bool isPaln(int y)
{
	for (int i = 0;i <= y;y++)
	{
		//even
		for (int j = 0;j < y;y++)
		{

		}
	}
}
bool isPrime(int x)
{
	if (x == 1)
		return 0;
	for (int i = 2;i*i < x;i++)
	{
		if (x%i == 0)
			return 0;
	}
	return 1;
}
int main()
{
	cin >> a, b;

	for (int i = 0;i < b;i++)
	{
		cin >> Num[i];
	}

	return 0;
}

