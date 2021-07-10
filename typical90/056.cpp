#include <iostream>
#include <vector>
#include <bitset>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

//37[ms]
int main(){
  int n,s;
  cin >> n >> s;
  vector<int> a(n), b(n);
  rep(i, n) cin >> a[i] >> b[i];
  vector<bitset<100001>> dp(n + 1);
  dp[0] = 1;
  rep(i, n){
    rep(j, s){
      if(!dp[i][j]) continue;
      if(j + a[i] <= s) dp[i + 1][j + a[i]] = 1;
      if(j + b[i] <= s) dp[i + 1][j + b[i]] = 1;
    }
  }
  if(!dp[n][s]){
    cout << "Impossible\n";
    return 0;
  }
  char ans[101];
  int last = s;
  for(int i = n - 1; i >= 0; i--){
    if(last - a[i] >= 0 && dp[i][last - a[i]]){
      last -= a[i];
      ans[i] = 'A';
    }else if(last - b[i] >= 0 && dp[i][last - b[i]]){
      last -= b[i];
      ans[i] = 'B';
    }else{
      cout << "Impossible\n";
      return 0;
    }
  }
  ans[n] = '\0';
  cout << ans << "\n";
}