#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MOD = 998244353;

int main(){
	int N, K;
	cin >> N >> K;

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

	ll ans = 0;
	vector<ll> A(N, 0);
	while(A[N-1] < K){
		bool isGood = true;
		for(int i = 0; i < N-2; i++){
			if((A[i] - A[i+1])*(A[i+1] - A[i+2]) >= 0){
				isGood = false;
				break;
			}
		}

		if(isGood){
			ans++;
		}

		A[0]++;
		for(int i = 0; i < N-1; i++){
			if(A[i] >= K){
				A[i] -= K;
				A[i+1]++;
			}
		}
	}

	cout << ans << endl;
}
