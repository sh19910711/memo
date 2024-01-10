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
    ri(n);
    rin(a,n);

    sort(a,a+n);

    int_t s=reduce(a,a+n);
    if (s==0) {
      cout << 0 << endl;
    } else if (2 * a[n-1] <= s) {
      cout << 1 << endl;
    } else {
      cout << 2*a[n-1] - s << endl;
    }
  }

  return 0;
}

/***
auto f = [&](int x) -> int { return x; };
tuple<int,string> x(42, "foo"); auto [t1, t2] = x;

flags: -Wall -Wextra -Wshadow -D_GLIBCXX_ASSERTIONS -DDEBUG -ggdb3 -fmax-errors=2 -std=c++17
https://codeforces.com/blog/entry/79024
***/