#include <iostream>
#include <string>
#include <vector>
#define mod 1000000007
using namespace std;

//19[ms]
string t = "atcoder";
int main(){
  int n;
  string s;
  cin >> n >> s;
  vector<vector<int>> dp(8, vector<int>(n + 1));
  for(int i = 0; i <= n; i++) dp[0][i] = 1;
  for(int i = 0; i < 7; i++){
    for(int j = 0; j < n; j++){
      if(t[i] == s[j]){
        dp[i + 1][j + 1] += dp[i][j];
        dp[i + 1][j + 1] %= mod;
      }
      dp[i + 1][j + 1] += dp[i + 1][j];
      dp[i + 1][j + 1] %= mod;
    }
  }
  cout << dp[7][n] << "\n";
}