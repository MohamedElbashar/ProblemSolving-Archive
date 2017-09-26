int t, n, b, totlen, w, lenbags[3], boxlen[11], boxw[11], boxp[11], ans = 0,
		idx[11];
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

		for (int i = 0; i < b; ++i) {
			cin >> boxlen[i] >> boxw[i] >> boxp[i];
			idx[i] = i;
		}

		do {
			int p = 0, len = 0, weight = 0 ,i = 0;
			for (int j = 0;j < n; j++) {
				len = 0;
				while(i < b){
					len += boxlen[idx[i]];
					weight += boxw[idx[i]];

					if (len > lenbags[j] ){
						weight -= boxw[idx[i]];
						break;
					}
					if(weight > w)
						break;
					p += boxp[idx[i]];
					i++;
				}

				if(weight > w)
					break;

			}

			ans = max(ans, p);
		} while (next_permutation(idx, idx + b));

		cout << ans << endl;
	}
	return 0;
}
