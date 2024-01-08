#include <bits/stdc++.h>
using namespace std;
#define loop ri(__num_cases); rep(__case,__num_cases)
#define rep(i, n) for (int i = 0; i < n; ++i)
#define per(i, n) for (int i = n-1; i >= 0; --i)
template <class ...Args> auto& __ri(Args &...args) { return (cin >> ... >> args); }
#define ri(...) int_t __VA_ARGS__; __ri(__VA_ARGS__)
#define rin(arr,num) int_t arr[num]; rep(i,num) cin >> arr[i]
typedef long long int_t;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  loop {
    // ri(n);
    // rin(a,n);
    // auto f = [&](int x) -> int { return x; };
    // tuple<int,string> x(42, "foo"); auto [t1, t2] = x;
    ri(n, k, d);
    rin(a, n);
    rin(b, k);

    [&]() {
      int_t res = 0;
      for(int i=0; i < 2*n && i < d; ++i) {
        int_t cur = 0; rep(j,n) if(a[j] == j+1) cur++;
        cur += (d-i-1)/2;
        res = max(res, cur);
        rep(j,b[i%k]) {
          a[j]++;
        }
      }
      cout << res << endl;
    }();
  }

  return 0;
}