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
    vi G[n];
    rep(i,n-1) {
      ri(s, t);
      G[s-1].push_back(t-1);
      G[t-1].push_back(s-1);
    }

    [&]() {
      int cnt = 0;
      rep(i,n) if(G[i].size()==1) cnt++;
      cout << (cnt+1)/2 << endl;
    }();
  }

  return 0;
}