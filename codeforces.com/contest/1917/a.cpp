#include <bits/stdc++.h>
using namespace std;
#define loop ri(__num_cases); rep(__case,__num_cases)
#define rep(i, n) for (int i = 0; i < n; ++i)
#define ri(v) int_t v; cin >> v;
#define rin(arr,num) int_t arr[num]; rep(i,num) cin >> arr[i]
typedef long long int_t;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  loop {
    ri(n);
    rin(a,n);

    [&]() {
      int cnt=0; rep(i,n) if(a[i]<0) cnt++;
      rep(i,n)if(a[i]==0) {
        cout << 0 << endl;
        return;
      }
      if(cnt%2==0) {
        cout << 1 << endl;
        cout << "1 0" << endl;
      } else {
        cout << 0 << endl;
      }
    }();
  }

  return 0;
}