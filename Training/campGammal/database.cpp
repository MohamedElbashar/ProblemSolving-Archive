-#include <algorithm>
#include <iostream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<cstdio>
#include<stdint.h>
#include<typeinfo>
#include<vector>

using namespace std;
int x;
bool Solve;
bool check(pair<int, int> a, pair<int, int> b) {
	if (b.first < a.first) {
		solve = true;
		return true;
	} else if (a.first == b.first) {
		if (a.second > b.second) {
			solve = true;	
			return true;
		}
	} else {
		solve = false;
		return false;
	}
	solve=false;
}
int main() {
5	cin >> x;
	pair<int, int> arr[x];
	for(int i=0;i<x;i++)	
	{
		cin>>arr[i].first>>arr[i].second;

	}
	sort(arr, arr + x, check);
	cout << endl;
	if (solve == false)
		cout << "impossible";
	else if (solve==true)
		cout << "possible";

	return 0;
}

