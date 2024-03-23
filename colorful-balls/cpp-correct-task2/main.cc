#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
	int Q;
	cin >> Q;

	int next = 1;
	vector<int> C(Q);
	vector<ll> A(Q);
	C[0] = 0;
	A[0] = 0;

	for(int q = 0; q < Q; q++){
		int t, c;
		ll x;
		cin >> t >> x >> c;
		if(t == 1){
			C[next] = c;
			A[next] = x;
			next++;
		}else if(t == 2){
			while(x > A[next - 1]){
				x -= A[next - 1];
				next--;
			}
			A[next - 1] -= x;
		}else{
			int look = next - 1;
			while(x > A[look]){
				x -= A[look];
				look--;
			}
			cout << C[look] << endl;
		}
	}
}
