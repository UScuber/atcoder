#include <iostream>
#include <vector>
#define mod 1000000007
using namespace std;

//10[ms]
int main(){
  int k;
  cin >> k;
  if(k % 9){
    cout << "0\n";
    return 0;
  }
  vector<int> dp(k + 1);
  dp[0] = 1;
  for(int i = 0; i < k; i++){
    for(int j = 1; j < 10; j++){
      if(i + j > k) break;
      dp[i + j] += dp[i];
      dp[i + j] %= mod;
    }
  }
  cout << dp[k] << "\n";
}