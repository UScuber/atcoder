#include <iostream>
#include <vector>
#include <string>
using namespace std;

//41[ms]
const int inf = 1000000000;
int main(){
  int n,k;
  string s;
  cin >> n >> k >> s;
  vector<vector<int>> dp(n + 1, vector<int>(26, inf));
  for(int i = n - 1; i >= 0; i--){
    for(int j = 0; j < 26; j++){
      if(s[i] - 'a' == j) dp[i][j] = i;
      else dp[i][j] = dp[i + 1][j];
    }
  }
  string ans = "";
  for(int i = 0; i < n; i++){
    for(int j = 0; j < 26; j++){
      if(dp[i][j] + k <= n){
        ans += j + 'a';
        k--;
        i = dp[i][j];
        break;
      }
    }
    if(!k) break;
  }
  cout << ans << "\n";
}