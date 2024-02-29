#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MOD = 998244353;

int main(){
	int N, K;
	cin >> N >> K;
	vector<vector<ll>> dp(N, vector<ll>(K, 0));

	// corner cases
	if(N == 1){
		cout << K << endl;
		return 0;
	}
	if(N == 2){
		ll ans = (K * (K - 1)) % MOD;
		cout << ans << endl;
		return 0;
	}

	// init dp table
	for(int i = 0; i < K; i++){
		dp[0][i] = 1;
	}

	// calc dp table
	for(int i = 0; i < N - 1; i++){
		ll sum = 0;
		for(int j = 0; j < K; j++){
			int look = (i % 2 == 0 ? j : K - j - 1);
			dp[i+1][look] = sum;
			sum += dp[i][look];
			sum %= MOD;
		}
	}

	ll ans = 0;
	for(int i = 0; i < K; i++){
		ans += dp[N-1][i];
	}
	ans *= 2;
	ans %= MOD;
	cout << ans << endl;
}
