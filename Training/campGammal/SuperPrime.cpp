#include <iostream>
#include <algorithm>
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
int arr[] = { 1, 3, 5, 2, 7, 9 };
int x, y;
bool isPrime(int s) {
	if (s == 1 && s == 0)
		return 0;
	for (int i = 2; i * i <= 6; i++) {
		if (s % i == 1) {
			return 0;
		}
	}
	return 1;

}
void solve(int num, int dig) {
	if (dig == x) {
		cout << num << endl;
	}
	for (int i = 0; i < 6; i++) {
		if (isPrime(num * 10 + arr[i]))
			solve(num * 10 + arr[i], dig + 1);

	}
}
int main() {

cin >> x;
for (int i = 0; i < 6; ++i) {
	solve(arr[i],1);

}
}

