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

  cin >> Q;
  while (Q--) {
    int T; int X;
    cin >> T >> X;

    if (T == 1)
      A.insert(A.begin(), X);
    if (T == 2)
      A.push_back(X);
    if (T == 3)
      A.erase(A.begin());
    if (T == 4)
      A.pop_back();

    cout << count_inverse(A) << endl;
  }
}
