#include"stdafx.h"
#include <iostream>
#include <string>
#include<string.h>
using namespace std;

int charToInt(char aChar)
{
	switch (aChar) {
	case '1': return 1;
	case '2': return 2;
	case '3': return 3;
	case '4': return 4;
	case '5': return 5;
	case '6': return 6;
	case '7': return 7;
	case '8': return 8;
	case '9': return 9;
	default:  return 0;
		break;
	}
}

int main()
{
	string input;
	int testcaseNb = 0;
	int n;
	int nums[26];
	int sum[26];
	int arr[26][26];
	while (true) {
		cin >> input;
		if (input == "bye") break;
		testcaseNb++;
		n = input.length();
		memset(arr, 0, sizeof arr);
		arr[1][1] = 1;
		nums[0] = 0;
		sum[0] = 0;
		for (int i = 1; i <= n; i++) {
			nums[i] = charToInt(input[i - 1]);
			sum[i] = sum[i - 1] + nums[i];
		}

		for (int i = 2; i <= n; i++)
			for (int j = 1; j <= i; j++) {
				int lastGroupSum = sum[i] - sum[i - j];
				int tempSum = 0;
				for (int k = 1; k <= i - j; k++) {
					tempSum = tempSum + nums[i - j - k + 1];
					if (tempSum > lastGroupSum) break;
					arr[i][j] += arr[i - j][k];
				}
				if (j == i)
					arr[i][j] = 1;
			}

		int finalRs = 0;
		for (int i = 1; i <= n; i++)
			finalRs += arr[n][i];
		cout << testcaseNb << ". " << finalRs << "\n";
	}
}