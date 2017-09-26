#include <bits/stdc++.h>
using namespace std;
int main() {
	string arr="ROYG";
	int n ;
	cin >> n;
	for(int i = 1 ; i <= n-3 ; i++){
		cout << arr[i%4];
	}
	cout << "BIV" << endl;

	return 0;

}
