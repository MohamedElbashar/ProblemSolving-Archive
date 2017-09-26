#include<bits/stdc++.h>
using namespace std;
int n, m, arr[1000001];
int res[50001];
int prim(int k)
{
	for (int i = 2; i <= sqrt(k); i++) {
		if (k % i == 0) {
			return false;
		}
	}
	return true;
}

int main()
{
	int  cnt = 0;
	int cunt = 0;
	scanf("%d",&n);
	for (int i = 0; i < n; i++) {
		scanf("%d",&arr[i]);
	}
	scanf("%d",&m);
	int a, b;
	while (cnt < m) {
		scanf("%d%d",&a,&b);
		for (int i = a; i <= b; i++) {
			if (prim(i)) {
				for (int j = 0; j < n; j++) {
					if (arr[j] % i == 0) {
						res[cunt]++;
					}
				}
			}
		}
		cunt++;
		cnt++;

	}
	for (int i = 0; i < m; i++) {

		printf("%d \n",res[i]);
	}
}
