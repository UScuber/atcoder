#include <iostream>
#include <vector>
using namespace std;
template<class T, class U>
T &chmin(T &a, const U &b){ if(a > b) a = b; return a; }

//29[ms]
const int inf = 1000000000;
int n;
vector<int> a;
vector<vector<int>> dp;
int dfs(int l, int r){
  if(dp[l][r] != inf) return dp[l][r]; //すでに値がわかっている
  if(r - l <= 1) return dp[l][r] = abs(a[l] - a[r]); //隣どうし

  chmin(dp[l][r], dfs(l+1, r-1) + abs(a[l] - a[r])); //両端を選ぶとき
  //二つに分けて考えるとき
  for(int i = l + 1; i < r; i += 2){
    chmin(dp[l][r], dfs(l, i) + dfs(i+1, r));
  }
  return dp[l][r];
}
int main(){
  cin >> n;
  n *= 2;
  a.resize(n);
  for(int i = 0; i < n; i++) cin >> a[i];
  dp.resize(n + 1, vector<int>(n + 1, inf));

  int ans = dfs(0, n - 1);
  cout << ans << "\n";
}