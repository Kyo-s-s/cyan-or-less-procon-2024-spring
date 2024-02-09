#include <cassert>
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class fenwick_tree {
 public:
  explicit fenwick_tree(int n) : _n(n), _dat(n) {}
  void add(int i, long long x) {
    assert(0 <= i && i < _n);
    ++i;
    while (i <= _n) {
      _dat[i-1] += x;
      i += i & -i;
    }
  }
  long long sum(int l, int r) {
    assert(0 <= l && l <= r && r <= _n);
    return _sum(r) - _sum(l);
  }
 private:
  int const _n;
  vector<long long> _dat;
  long long _sum(int r) {
    long long s = 0;
    while (r > 0) {
      s += _dat[r-1];
      r -= r & -r;
    }
    return s;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  constexpr int offset = 1000000;
  int N, Q;
  cin >> N;
  deque<int> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
    A[i] += offset;
  }

  constexpr int inf = 2000001;
  long long answer = 0;
  fenwick_tree cnt(inf);
  for (int const &val : A) {
    answer += cnt.sum(val+1, inf);
    cnt.add(val, 1);
  }

  cin >> Q;
  while (Q--) {
    string T; int X;
    cin >> T >> X;

    X += offset;
    if (T == "push_front") {
      answer += cnt.sum(0, X);
      cnt.add(X, 1);
      A.push_front(X);
    }
    if (T == "push_back") {
      answer += cnt.sum(X+1, inf);
      cnt.add(X, 1);
      A.push_back(X);
    }
    if (T == "pop_front") {
      answer -= cnt.sum(0, A.front());
      cnt.add(A.front(), -1);
      A.pop_front();
    }
    if (T == "pop_back") {
      answer -= cnt.sum(A.back()+1, inf);
      cnt.add(A.back(), -1);
      A.pop_back();
    }

    cout << answer << '\n';
  }
}
