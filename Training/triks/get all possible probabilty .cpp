#include <bits/stdc++.h>
using namespace std;
vector<string> s;
void print_all_strings(char set[], string str, int n, int k)

{
	if (k == 1){

		for (int j = 0; j < n; j++)
			s.push_back(str + set[j]);
	}
	else{

		for (int i = 0; i < n; i++)
			print_all_strings(set, str + set[i], n, k - 1);
	}
}

int main()

{
	int k = 3;

	char set[] = { '+', '-' };
	int n = sizeof set;

	print_all_strings(set, "", n, k);
	for (int i = 0; i < s.size(); i++) {
		cout << s[i] << endl;
	}

	return 0;

}

