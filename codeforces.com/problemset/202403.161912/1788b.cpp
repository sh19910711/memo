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
    string s; cin >> s;
    int l=s.size();

    string a(l, ' '), b(l, ' ');
    bool f=true;
    rep(i,l) {
      if((s[i]-'0')%2 == 0) {
        a[i] = b[i] = (s[i]-'0')/2 + '0';
      } else if(f) {
        a[i] = (s[i]-'0'+1)/2 + '0';
        b[i] = (s[i]-'0'-1)/2 + '0';
        f = !f;
      } else {
        a[i] = (s[i]-'0'-1)/2 + '0';
        b[i] = (s[i]-'0'+1)/2 + '0';
        f = !f;
      }
    }

    rep(i,l) if(a[i] == '0') a[i]=' '; else break;
    if(a[l-1]==' ')a[l-1]='0';
    rep(i,l) if(b[i] == '0') b[i]=' '; else break;
    if(b[l-1]==' ')b[l-1]='0';
    cout << a << " " << b << endl;
  }

  return 0;
}

/***
  [&]() { cout << "none" << endl; }();
  auto f = [&](int x) -> int { return x; };
  tuple<int,string> x(42, "foo"); auto [t1, t2] = x;
***/