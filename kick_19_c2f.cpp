#include <bits/stdc++.h>
#define N 100010
#define ll long long int
#define LD long double

using namespace std;

ll mod = 1000000007;

int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    for(int t = 1; t <= T; t++) {
		int R, C, K;
		cin >> R >> C >> K;

		int V[R + 1][C + 1];
		for(int i = 1; i <= R; i++) {
			for(int j = 1; j <= C; j++) {
				cin >> V[i][j];
			}
		}

		int cnt[R + 1][C + 1];

		for(int i = 1; i <= R; i++) {
			for(int j = 1; j <= C; j++) {
				int maxi = V[i][j], mini = V[i][j];
				for(int k = j; k <= C; k++) {
					maxi = max(maxi, V[i][k]);
					mini = min(mini, V[i][k]);
					if(maxi - mini <= K) {
						cnt[i][j] = k;
					}
					else {
						break;
					}
				}
			}
		}

		int ans = 1;

		for(int i = 1; i <= R; i++) {
			for(int j = 1; j <= C; j++) {
				int mini = cnt[i][j];
				for(int k = i; k <= R; k++) {
					mini = min(mini, cnt[k][j]);
					ans = max(ans, (mini - j + 1) * (k - i + 1));
				}
			}
		}

		cout << "Case #" << t << ": " << ans << "\n";
	}
    
	return 0;
}