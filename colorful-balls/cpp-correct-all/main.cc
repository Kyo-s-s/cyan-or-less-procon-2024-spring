#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
	int Q;
	cin >> Q;

	int next = 1;
	vector<int> C(Q);
	vector<ll> A(Q), S(Q);
	C[0] = 0;
	A[0] = 0;
	S[0] = 0;

	for(int q = 0; q < Q; q++){
		int t;
		ll x;
		cin >> t >> x;
		if(t == 1){
			int c;
			cin >> c;
			C[next] = c;
			A[next] = x;
			S[next] = S[next - 1] + A[next];
			next++;
		}else{
			ll req = S[next - 1] - x;

			// (left, right]
			int left = 0;
			int right = next - 1;
			while(right - left > 1){
				int mid = (left + right) / 2;
				if(S[mid] > req){
					right = mid;
				}else{
					left = mid;
				}
			}

			if(t == 2){
				A[right] -= x - (S[next - 1] - S[right]);
				S[right] -= x - (S[next - 1] - S[right]);
				next = right + 1;
				if(A[right] == 0){
					next--;
				}
			}else{
				cout << C[right] << endl;
			}
		}
	}
}
