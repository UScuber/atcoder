#include <iostream>
#include <vector>
#define mod 1000000007
using namespace std;

//8[ms]
int main(){
  int n,l;
  cin >> n >> l;
  vector<int> dp(n + 1);
  dp[0] = 1;
  for(int i = 0; i < n; i++){
    dp[i + 1] = dp[i];
    if(i-l+1 >= 0) dp[i + 1] += dp[i - l + 1];
    dp[i + 1] %= mod;
  }
  cout << dp[n] << "\n";
}