#include <bits/stdc++.h>
using namespace std;
#define loop ri(__num_cases); rep(__case,__num_cases)
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep3(i, j, k, n) rep(i,n)rep(j,n)rep(k,n)
#define per(i, n) for (int i = n-1; i >= 0; --i)
template <class ...Args> auto& __ri(Args &...args) { return (cin >> ... >> args); }
#define ri(...) int_t __VA_ARGS__; __ri(__VA_ARGS__)
#define rin(arr, num) int_t arr[num]; rep(i,num) cin >> arr[i]
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
    ri(n); rin(a,n);

    vi pos, neg; rep(i,n) if(a[i]>0) pos.push_back(a[i]); else if (a[i]<0) neg.push_back(a[i]);
    vi zero; rep(i,n) if(a[i] == 0) if(zero.size() < 3) zero.push_back(0);

    vi arr;
    arr.insert(arr.begin(), all(pos));
    arr.insert(arr.begin(), all(neg));
    arr.insert(arr.begin(), all(zero));

    // pvec(arr);
    [&]() {
      if(pos.size() > 2 || neg.size() > 2) {
        cout << "NO" << endl;
        return;
      }
      
      int nn=arr.size();
      rep3(i,j,k,nn)if(i<j && j<k){
        bool flag=false;
        rep(x,nn) if (arr[i]+arr[j]+arr[k] == arr[x]) flag = true;
        if(!flag) {
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