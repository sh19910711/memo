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
    ri(n); rin(a,n);
    reverse(a, a+n);

    auto f = [](int_t* a, int n) -> int_t {
      rep(i,n) if(i>0) if(a[i] != a[0]) return i;
      return n;
    };
    // [f]() { int_t aa[4]{1,2,3,4}; dbg(f(aa, 4)); assert(f(aa, 4) == 1); }();
    // [f]() { int_t aa[4]{1,1,1,4}; dbg(f(aa, 4)); assert(f(aa, 4) == 3); }();
    // [f]() { int_t aa[4]{1,1,1,1}; dbg(f(aa, 4)); assert(f(aa, 4) == 4); }();

    int_t res=0;
    while(f(a, n) < n) {
      int_t x = f(a, n);
      rep(i, 2*x) if(i<n) a[i] = a[0];
      res++; 
    }

    cout << res << endl;
  }

  return 0;
}

/***
  [&]() { cout << "none" << endl; }();
  auto f = [&](int x) -> int { return x; };
  tuple<int,string> x(42, "foo"); auto [t1, t2] = x;
***/