#include <cassert>
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class fenwick_tree {
 public:
  explicit fenwick_tree(int n) : _n(n), _dat(n) {}
  void add(int i, int x) {
    assert(0 <= i && i < _n);
    ++i;
    while (i <= _n) {
      _dat[i-1] += x;
      i += i & -i;
    }
  }
  int sum(int l, int r) {
    assert(0 <= l && l <= r && r <= _n);
    return _sum(r) - _sum(l);
  }
 private:
  int const _n;
  vector<int> _dat;
  int _sum(int r) {
    int s = 0;
    while (r > 0) {
      s += _dat[r-1];
      r -= r & -r;
    }
    return s;
  }
};

int count_inverse(deque<int> const &A) {
  constexpr int INF = 200000 + 1;
  constexpr int OFFSET = 100000;
  fenwick_tree cnt(INF);
  int answer = 0;
  for (int const a : A) {
    answer += cnt.sum(a+1 + OFFSET, INF);
    cnt.add(a + OFFSET, 1);
  }
  return answer;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, Q;
  cin >> N;
  assert(N <= 5000);
  deque<int> A(N);
  for (int i = 0; i < N; ++i)
    cin >> A[i];

  cin >> Q;
  assert(Q <= 100);
  while (Q--) {
    string T; int X;
    cin >> T >> X;

    if (T == "push_front")
      A.push_front(X);
    if (T == "push_back")
      A.push_back(X);
    if (T == "pop_front")
      A.pop_front();
    if (T == "pop_back")
      A.pop_back();

    cout << count_inverse(A) << '\n';
  }
}
