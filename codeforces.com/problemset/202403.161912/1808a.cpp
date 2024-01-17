#include <bits/stdc++.h>
using namespace std;
#define loop ri(__num_cases); rep(__case,__num_cases)
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep3(i, j, k, n) rep(i,n)rep(j,n)rep(k,n)
#define per(i, n) for (int i = n-1; i >= 0; --i)
template <class ...Args> auto& __ri(Args &...args) { return (cin >> ... >> args); }
#define ri(...) int_t __VA_ARGS__; __ri(__VA_ARGS__)
#define rin(arr,num) int_t arr[num]; rep(i,num) cin >> arr[i]
typedef long long int_t;
typedef vector<int_t> vi;
#define all(vec) vec.begin(), vec.end()
#define dbg(v) cout << "# L" << __LINE__ << ": " << #v << " = " << v << endl;
#define dbgvec(vec) for(auto v:vec) cout << v << ", "; cout << endl

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  loop {
    ri(l,r);
    auto ma = [](int n) {
      int res=-1;
      while(n>0) {
        res = max(res, n%10);
        n /= 10;
      }
      return res;
    };
    auto mi = [](int n) {
      int res=10;
      while(n>0) {
        res = min(res, n%10);
        n /= 10;
      }
      return res;
    };
    typedef tuple<int_t, int_t> node_t;
    node_t res(-1,-1);
    rep(i,100) if(l <= l+i && l+i <= r) res = max(res, node_t(ma(l+i)-mi(l+i), l+i));
    auto [_, res_i] = res;
    cout << res_i << endl;
  }

  return 0;
}

int main2() {
  const int N=1000000+1;
  int x[N];
  rep(i,N) {
    int t=i;
    int ma=-1,mi=10;
    while(t>0) { ma=max(ma,t%10); mi=min(mi,t%10); t/=10; }
    x[i]=ma-mi;
  }
  set<int,greater<int>> s[10];
  rep(i,N)if(i>0) {
    s[x[i]].insert(i);
  }

  loop {
    // ri(n); rin(a,n);
    ri(l,r);
    per(i,10) {
      auto it = s[i].lower_bound(r);
      if (it == s[i].end()) continue;
      if (l <= *it && *it <= r) {
        cout << *it << endl;
        break;
      }
    }
  }

  return 0;
}

/***
  [&]() { cout << "none" << endl; }();
  auto f = [&](int x) -> int { return x; };
  tuple<int,string> x(42, "foo"); auto [t1, t2] = x;
***/