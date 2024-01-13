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
    ri(n,m,r,c); r--; c--;
    string s[n]; rep(i,n) cin >> s[i];

    [&]() {
      int cnt=0; rep(i,n)rep(j,m)if(s[i][j] == 'B') cnt++;
      if (cnt==0) {
        cout << -1 << endl;
        return;
      }
      if (s[r][c] == 'B') {
        cout << 0 << endl;
        return;
      }
      rep(i,n)if(s[i][c] == 'B') { cout << 1 << endl; return; }
      rep(i,m)if(s[r][i] == 'B') { cout << 1 << endl; return; }

      cout << 2 << endl;
    }();
  }

  return 0;
}

/***
  [&]() { cout << "none" << endl; }();
  auto f = [&](int x) -> int { return x; };
  tuple<int,string> x(42, "foo"); auto [t1, t2] = x;
***/