#include <bits/stdc++.h>
using namespace std;
#define loop ri(__num_cases); rep(__case,__num_cases)
#define rep(i, n) for (int i = 0; i < n; ++i)
#define per(i, n) for (int i = n-1; i >= 0; --i)
#define ri(v) int_t v; cin >> v;
#define rin(arr,num) int_t arr[num]; rep(i,num) cin >> arr[i]
typedef long long int_t;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  loop {
    ri(n);
    string s; cin >> s;

    [&]() {
      int_t dp[n];
      int nx[26];
      dp[n-1] = 1;
      fill(nx, nx+26, n);
      nx[s[n-1]-'a'] = n-1;
      per(i,n) if(i<n-1) {
        dp[i] = dp[i+1] + (nx[s[i]-'a'] - i);
        nx[s[i]-'a'] = i;
      }
      cout << dp[0] << endl;
    }();
  }

  return 0;
}