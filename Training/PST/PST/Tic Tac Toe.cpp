#include <bits/stdc++.h>
using namespace std;
int t, cntx, cnto;
char arr[3][3];
int solve(char c) {
	return (arr[0][0] == c && arr[0][1] == c && arr[0][2] == c)
			|| (arr[1][0] == c && arr[1][1] == c && arr[1][2] == c)
			|| (arr[2][0] == c && arr[2][1] == c && arr[2][2] == c)
			|| (arr[0][1] == c && arr[1][1] == c && arr[2][1] == c)
			|| (arr[0][0] == c && arr[1][0] == c && arr[2][0] == c)
			|| (arr[0][0] == c && arr[1][1] == c && arr[2][2] == c)
			|| (arr[0][2] == c && arr[1][1] == c && arr[2][0] == c)
			|| (arr[0][2] == c && arr[1][2] == c && arr[2][2] == c);
}
int main() {
	freopen("myfile.txt", "w", stdout);
	cin >> t;
	while (t--) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cin >> arr[i][j];
				if (arr[i][j] == 'X') {
					cntx++;
				} else if (arr[i][j] == 'O') {
					cnto++;
				}
			}
		}
		int x = solve('X');
		int o = solve('O');
		if ((x && o) || (x && cntx - cnto != 1) || (o && cntx - cnto != 0)
				|| (cntx - cnto != 1 && cntx - cnto != 0)) {
			cout << "no" << endl;
		} else {
			cout << "yes" << endl;
		}

		cnto = 0;
		cntx = 0;
	}

}
