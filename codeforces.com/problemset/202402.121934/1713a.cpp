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
    ri(n);
    int_t res=0;
    int_t max_a=0,min_a=0,max_b=0,min_b=0;
    rep(i,n) {
      ri(a, b);
      max_a = max(max_a, a);
      max_b = max(max_b, b);
      min_a = min(min_a, a);
      min_b = min(min_b, b);
    }
    res = (abs(max_a) + abs(min_a) + abs(max_b) + abs(min_b)) * 2;
    cout << res << endl;
  }

  return 0;
}

/***
  [&]() { cout << "none" << endl; }();
  auto f = [&](int x) -> int { return x; };
  tuple<int,string> x(42, "foo"); auto [t1, t2] = x;
***/