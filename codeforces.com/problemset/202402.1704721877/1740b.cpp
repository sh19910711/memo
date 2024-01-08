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
    // ri(n);
    // rin(a,n);
    // auto f = [&](int x) -> int { return x; };
    // tuple<int,string> x(42, "foo"); auto [t1, t2] = x;
    ri(n);
    tuple<int_t, int_t> x[n]; rep(i,n) {
      ri(a, b);
      if (a > b) swap(a, b);
      x[i] = make_tuple(b, a);
    }
    sort(x, x+n);

    [&]() {
      int_t res = 0;
      rep(i,n) {
        auto [_, a] = x[i];
        res += 2 * a;
      }
      rep(i,n) if(i+1<n) {
        auto [b1, _1] = x[i];
        auto [b2, _2] = x[i+1];
        res += b2 - b1;
      }
      res += get<0>(x[0]);
      res += get<0>(x[n-1]);
      cout << res << endl;
    }();
  }

  return 0;
}