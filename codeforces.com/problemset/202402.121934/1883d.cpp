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
    
  multiset<int_t, greater<int_t>> sl;
  multiset<int_t> sr;

  loop {
    string s; int_t l, r; cin >> s >> l >> r;

    if(s == "+") {
      sl.insert(l);
      sr.insert(r);
    } else if (s == "-") {
      sl.erase(sl.find(l));
      sr.erase(sr.find(r));
    }

    [&]() {
      if (sl.size() < 2) {
        cout << "NO" << endl;
        return;
      }
      if (*sl.begin() <= *sr.begin()) {
        cout << "NO" << endl;
        return;
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