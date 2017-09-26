#include <iostream>
#include<algorithm>
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

int NumOfLines, Capacity;
int item[100][2];
int ret1 = 0, ret2 = 0, mx;

void check(pair<int, int> a, pair<int, int> b) {
	for (int i = 0; i < NumOfLines; i++) {
		if (a.first + b.first <= Capacity) {
			if (a.first != b.first) {
				ret1 = a.second + b.second;
			}
			if (a.first == b.first) {
				ret2 = a.second + b.second;
			}
		}
		mx = max(ret1, ret2);
	}
}
	bool cmp(pair<int, int> a, pair<int, int> b) {
	 if (a.second < b.second) {
	 return true;
	 }
	 }
int main() {
	cin >> Capacity >> NumOfLines;
	pair<int, int> item[NumOfLines];
	for (int i = 0; i < NumOfLines; i++) {
		cin >> item[i].first >> item[i].second;
	}
	sort(item, item + NumOfLines, cmp);

}

/*cout << endl;
 pair<int, int> arr[NumOfLinesm];
 for (int i = 0; i < 2; i++) {
 for (int j = 0; j < NumOfLines; j++) {
 cin >> item[i][j];
 }
 }

 /*for (int i = 0; i < NumOfLines; i++) {
 for (int j = 1; j < NumOfLines; j++) {
 if (item[i][j] < item[i + j][j + 1]) {
 int temp = item[i + j][j + 1];
 item[i + j][j + 1] = item[i][j];
 item[i][j] = temp;
 }
 }
 }
 cout << item[NumOfLines][2];*/
}
