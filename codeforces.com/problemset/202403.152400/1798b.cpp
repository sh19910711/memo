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

const int num = 50001;
int b[num];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  loop {
    // ri(n); rin(a,n);
    ri(m);
    vi a[m]; rep(i,m) {
      ri(n); rin(aa, n);
      a[i] = vi(aa, aa+n);
    }

    rep(i,m)rep(j,a[i].size()) b[a[i][j]-1] = i;
    // dbgvec(vi(b,b+10));

    int res[m];
    fill(res,res+m,-1);
    set<int_t> s; rep(i,m)for(auto v:a[i]) s.insert(v-1);
    for(auto i:s)if(b[i] != -1)res[b[i]] = i+1;
    [&]() {
      rep(i,m)if(res[i] == -1) {
        cout << -1 << endl;
        return;
      }
      rep(i,m)cout<<res[i]<<" ";
      cout<<endl;
    }();
  }

  return 0;
}

/***
  [&]() { cout << "none" << endl; }();
  auto f = [&](int x) -> int { return x; };
  tuple<int,string> x(42, "foo"); auto [t1, t2] = x;
***/