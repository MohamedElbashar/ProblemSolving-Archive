#include <bits/stdc++.h>
using namespace std;
/**************BASHAR*****************/
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
#define mem(a,b) memset(a,b,sizeof(a))
#define ll long long
#define oo 1e9
#define fir first
#define sec second
int di[] = { 1, -1, 0, 0 };
int dj[] = { 0, 0, 1, -1 };
/**************BASHAR*****************/
int t, n;
int arr[9][9];

int main() {
	scanf("%d", &t);
	while (t--) {
		int flag = 1;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 2; j++) {
				scanf("%d", &arr[i][j]);
			}
		}
		if (n == 1) {
			cout << "weak" << endl;
			continue;
		}
		for (int i = 0; i < n-1; i++) {
			if (arr[i][0] != arr[i + 1][0]) {
				if (arr[i][1] != arr[i + 1][1]) {
					flag = 0;
					cout << "strong" << endl;
					break;
				}
			}
		}
		if (flag)
			cout << "weak" << endl;
	}

}
