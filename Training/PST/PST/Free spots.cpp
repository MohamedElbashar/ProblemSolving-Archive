#include <bits/stdc++.h>
using namespace std;
//freopen("myfile.txt", "w", stdout);
int main() {
	int w, h, n;
	//freopen("myfile.txt", "w", stdout);
	while (cin >> w >> h >> n, w != 0) {
		int arr[510][510];
		memset(arr, 0, sizeof arr);
		int cnt = w * h;
		for (int i = 0; i < n; i++) {
			int x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			for (int x = min(x1, x2) - 1; x <= max(x1, x2) - 1; x++)
				for (int y = min(y1, y2) - 1; y <= max(y1, y2) - 1; y++) {
					if (arr[x][y] == 0) {
						cnt--;
						arr[x][y] = 1;
					}
				}
		}
		if (cnt == 0)
			cout << "There is no empty spots." << endl;
		else if (cnt == 1)
			cout << "There is one empty spot." << endl;
		else
			cout << "There are " << cnt << " empty spots." << endl;
	}
	return 0;
}
