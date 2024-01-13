#include <bits/stdc++.h>
using namespace std;
#define loop ri(__num_cases); rep(__case,__num_cases)
#define rep(i, n) for (int i = 0; i < n; ++i)
#define per(i, n) for (int i = n-1; i >= 0; --i)
template <class ...Args> auto& __ri(Args &...args) { return (cin >> ... >> args); }
#define ri(...) int_t __VA_ARGS__; __ri(__VA_ARGS__)
#define rin(arr,num) int_t arr[num]; rep(i,num) cin >> arr[i]
typedef long long int_t;
typedef vector<int_t> vi;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  loop {
    ri(m);
    const int N = 50000+1;
    int b[N];
    fill(b, b+N, -1);

    set<int_t> bb;
    rep(i,m) {
      ri(an);
      rep(j,an) {
        ri(aij);
        b[aij] = max(b[aij], i);
        bb.insert(aij);
      }
    }

    int_t s[m];
    fill(s, s+m, -1);
    for (auto bi : bb) {
      s[b[bi]] = bi;
    }

    [&]() {
      rep(i,m) if(s[i] == -1) {
        cout << -1 << endl;
        return;
      }

      rep(i,m) cout << s[i] << " ";
      cout << endl;
    }();
  }

  return 0;
}

/***
  [&]() { cout << "none" << endl; }();
  auto f = [&](int x) -> int { return x; };
  tuple<int,string> x(42, "foo"); auto [t1, t2] = x;
***/