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
    // ri(n); rin(a,n);
    ri(n);
    int_t a[n], x[n]; rep(i,n) cin>>a[i]>>x[i];
    int_t l=0, r=1e9+1;
    rep(i,n)if(a[i]==1) l=max(l, x[i]);
    rep(i,n)if(a[i]==2) r=min(r, x[i]);
    int_t s[n]; int sn=0; rep(i,n)if(a[i]==3) s[sn++] = x[i]; sort(s,s+sn);
    // dbg(l); dbg(r);
    [&]() {
      cout << max(0LL, r-l+1 - (upper_bound(s,s+sn,r)-lower_bound(s,s+sn,l))) << endl;
    }();
  }

  return 0;
}

/***
  [&]() { cout << "none" << endl; }();
  auto f = [&](int x) -> int { return x; };
  tuple<int,string> x(42, "foo"); auto [t1, t2] = x;
***/