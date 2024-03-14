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

  int N, Q;
  cin >> N;
  deque<int> A(N);
  for (int i = 0; i < N; ++i)
    cin >> A[i];

  constexpr int INF = 200000 + 1;
  constexpr int OFFSET = 100000;
  long long answer = 0;
  fenwick_tree cnt(INF);
  for (int const a : A) {
    answer += cnt.sum(a+1 + OFFSET, INF);
    cnt.add(a + OFFSET, 1);
  }

  cin >> Q;
  while (Q--) {
    int T; cin >> T;

    if (T == 3) { // push_front
      int X; cin >> X;
      answer += cnt.sum(0, X + OFFSET);
      cnt.add(X + OFFSET, 1);
      A.push_front(X);
    }
    if (T == 1) { // push_back
      int X; cin >> X;
      answer += cnt.sum(X+1 + OFFSET, INF);
      cnt.add(X + OFFSET, 1);
      A.push_back(X);
    }
    if (T == 4) { // pop_front
      answer -= cnt.sum(0, A.front() + OFFSET);
      cnt.add(A.front() + OFFSET, -1);
      A.pop_front();
    }
    if (T == 2) { // pop_back
      answer -= cnt.sum(A.back()+1 + OFFSET, INF);
      cnt.add(A.back() + OFFSET, -1);
      A.pop_back();
    }

    cout << answer << '\n';
  }
}
