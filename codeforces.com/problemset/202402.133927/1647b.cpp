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

int si[100][100];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  loop {
    ri(n,m);
    string s[n]; rep(i,n)cin>>s[i];
    rep(i,n)rep(j,m)si[i][j] = s[i][j]-'0';

    [&]() {
      rep(i,n)rep(j,m)if(i+1<n&&j+1<m) {
        if(si[i][j]+si[i+1][j]+si[i][j+1]+si[i+1][j+1] == 3) {
          cout << "NO" << endl;
          return;
        }
      }
      cout << "YES" << endl;
    }();
  }

  return 0;
}

/***
  [&]() { cout << "none" << endl; }();
  auto f = [&](int x) -> int { return x; };
  tuple<int,string> x(42, "foo"); auto [t1, t2] = x;
***/