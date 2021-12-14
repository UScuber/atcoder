#include <iostream>
#include <vector>

//101[ms]
#define rep(i, n) for(int i = 0; i < n; i++)
using ll = long long;
#define mod 1000000007
using namespace std;

int n;
vector<char> c;
vector<vector<int>> root;
ll ans = 0;
void dfs(int pos, int par, vector<vector<ll>> &dp){
  ll val = 1, val2 = 1;
  for(int x : root[pos]){
    if(x == par) continue;
    dfs(x, pos, dp);
    if(c[pos] == 'a') val *= dp[x][0] + dp[x][2];
    else val *= dp[x][1] + dp[x][2];
    val2 *= dp[x][0] + dp[x][1] + 2 * dp[x][2];
    val %= mod;
    val2 %= mod;
  }
  if(c[pos] == 'a') dp[pos][0] = val;
  else dp[pos][1] = val;
  dp[pos][2] = val2 - val;
  if(dp[pos][2] < 0) dp[pos][2] += mod;
}
int main(){
  cin >> n;
  c.resize(n);
  root.resize(n);
  rep(i, n) cin >> c[i];
  rep(i, n - 1){
    int a,b;
    cin >> a >> b;
    a--; b--;
    root[a].push_back(b);
    root[b].push_back(a);
  }
  vector<vector<ll>> dp(n, vector<ll>(3));
  dfs(0, -1, dp);
  cout << dp[0][2] << "\n";
}