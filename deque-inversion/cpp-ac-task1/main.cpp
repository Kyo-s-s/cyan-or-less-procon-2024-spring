#include <cassert>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int count_inverse(vector<int> const &A) {
  int cnt = 0;
  for (size_t i = 0; i < A.size(); ++i)
    for (size_t j = i+1; j < A.size(); ++j)
      if (A[i] > A[j])
        ++cnt;
  return cnt;
}

int main() {
  int N, Q;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; ++i)
    cin >> A[i];
  assert(N <= 100);

  cin >> Q;
  assert(Q <= 100);
  while (Q--) {
    int T; int X;
    cin >> T >> X;
    assert(T == 2 or T == 4);
    if (T == 2)
      A.push_back(X);
    if (T == 4)
      A.pop_back();
    cout << count_inverse(A) << endl;
  }
}
