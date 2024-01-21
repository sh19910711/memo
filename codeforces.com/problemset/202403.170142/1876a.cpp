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
#define F first
#define S second

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  loop {
    // ri(n); rin(a,n);
    ri(n,p); rin(a,n); rin(b,n);

    typedef pair<int_t,int_t> P;
    P s[n];
    rep(i,n) s[i]=P(b[i],a[i]);
    sort(s,s+n);

    int_t res=0;
    priority_queue<P,vector<P>,greater<P>> q;
    q.emplace(p,n);
    rep(i,n) {
      auto [b,a] = q.top(); q.pop();
      res+=b;
      a--;
      if (a>0) q.emplace(b, a);
      q.emplace(s[i].F, s[i].S);
    }
    
    // dbg(res);
    cout << res << endl;
  }

  return 0;
}

/***
  [&]() { cout << "none" << endl; }();
  auto f = [&](int x) -> int { return x; };
  tuple<int,string> x(42, "foo"); auto [t1, t2] = x;
***/