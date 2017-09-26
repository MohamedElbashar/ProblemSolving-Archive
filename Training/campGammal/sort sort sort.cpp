#include"stdafx.h"
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
#include<set>
using namespace std;
int N, M, arr[10001];
bool cmp(int b, int a) {
	int modA = a % M;
	int modB = b % M;
	if (modB == modA) {
		if (b % 2 == 0 && a % 2 == 1) {
			return b < a;
		}
		else if (b % 2 == 1 && a % 2 == 0) {
			return a < b;
		}
		else if (b % 2 == 0 && a % 2 == 0) {
			if (a < b){
		     	return b < a;
			}
			else{
				return a < b;
			}
		}
		else if (b % 2 == 1 && a % 2 == 1) {
			if (a < b){
				return a < b;
			}
			else{
				return b < a;
			}
		}
	}
	return modB < modA;
}
int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		arr[i - 1] = i;
		cout << arr[i - 1];
		cout << endl;
	}
	sort(arr, arr + N, cmp);
	cout << "OutPut";
	cout << endl;
	for (int i = 0; i < N; i++) {
		cout << arr[i];
		cout << endl;
	}
	return 0;
}
