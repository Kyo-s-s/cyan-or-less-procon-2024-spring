#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
	int Q;
	cin >> Q;

	int next = 1;
	vector<int> C(Q);
	C[0] = 0;

	for(int q = 0; q < Q; q++){
		int t, c;
		ll x;
		cin >> t >> x >> c;
		if(t == 1){
			C[next] = c;
			next++;
		}else if(t == 2){
			next--;
		}else{
			cout << C[next - x] << endl;
		}
	}
}
