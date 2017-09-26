#include "stdafx.h"
#include<iostream>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;
int lcs[6101][6101];

int LCS(string A, string B)
{
	for (int i = 0; i <= A.length(); i++) {
		for (int j = 0; j <= B.length(); j++) {
			if (i == 0 || j == 0) {
				lcs[i][j] = 0;
			}
			else if (A[i - 1] == B[i - 1]) {
				lcs[i][j] = lcs[i - 1][j - 1] + 1;
			}
			else {
				lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
			}
		}
	}
	return lcs[A.length()][B.length()];
}
int main()
{
	int t;
	string S, R;
	scanf("%d", &t);
	getline(cin, S);
	while (t--) {
		getline(cin, S);
		R = S;
		for (int i = 0, j = R.size() - 1; i < j; ++i, --j) {
			char temp = R[i];
			R[i] = R[j];
			R[j] = temp;
		}
		printf("%d\n", S.length() - LCS(S, R));
	}
	return 0;
}

