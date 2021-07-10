#include <iostream>
#include <vector>
using ll = long long;
using namespace std;

//78[ms]
void dfs(vector<vector<int>> &root, int pos, int par, vector<int> &dp){
  dp[pos] = 1;
  for(int x : root[pos]){
    if(x == par) continue;
    dfs(root, x, pos, dp);
    dp[pos] += dp[x];
  }
}
int main(){
  int n;
  cin >> n;
  vector<vector<int>> root(n);
  vector<int> a(n - 1), b(n - 1);
  for(int i = 0; i < n - 1; i++){
    cin >> a[i] >> b[i];
    a[i]--; b[i]--;
    root[a[i]].push_back(b[i]);
    root[b[i]].push_back(a[i]);
  }
  vector<int> dp(n);
  dfs(root, 0, -1, dp);
  ll ans = 0;
  for(int i = 0; i < n - 1; i++){
    ll t = min(dp[a[i]], dp[b[i]]);
    ans += t * (n - t);
  }
  cout << ans << "\n";
}