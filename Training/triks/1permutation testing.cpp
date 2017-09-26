int main() {
	freopen("in.txt", "r", stdin);
	cin >> t;
	while (t--) {
		cin >> n >> b >> w;
		totlen = 0;
		ans = 0;

		for (int i = 0; i < n; i++) {
			cin >> lenbags[i];
			totlen += lenbags[i];
		}
		for (int i = 0; i < b; ++i){
			cin >> boxlen[i] >> boxw[i] >> boxp[i];
			idx[i] = i;
		}
		do {
			int p = 0 ,len = 0, weight = 0;

			for (int i = 0; i < b; i++) {
				len += boxlen[ idx[i] ];
				weight += boxw[idx[i]];

				if (len > totlen || weight > w)
					break;

				p += boxp[idx[i]];
			}

			ans = max(ans , p);
		} while (next_permutation(idx, idx + b));

		cout << ans << endl;
	}
	return 0;
}
