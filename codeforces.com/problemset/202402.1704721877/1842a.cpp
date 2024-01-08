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
    ri(n, m);
    rin(a,n);
    rin(b,m);

    [&]() {
      // int_t sa = 0; rep(i,n) sa += a[i];
      int_t sa = reduce(a,a+n);
      int_t sb = 0; rep(i,m) sb += b[i];
      if (sa > sb) {
        cout << "Tsondu" << endl;
      } else if (sb > sa) {
        cout << "Tenzing" << endl;
      } else {
        cout << "Draw" << endl;
      }
    }();
  }

  return 0;
}