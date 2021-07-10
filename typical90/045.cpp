#include <iostream>
#include <vector>
#define rep(i, n) for(int i = 0; i < n; i++)
using ll = long long;
using namespace std;
template<class T, class U>
T &chmax(T &a, const U &b){ if(a < b) a = b; return a; }
template<class T, class U>
T &chmin(T &a, const U &b){ if(a > b) a = b; return a; }

//270[ms]
int main(){
  int n,k;
  cin >> n >> k;
  vector<ll> x(n), y(n);
  rep(i, n) cin >> x[i] >> y[i];
  vector<ll> dist(1 << n);
  rep(i, 1 << n){
    rep(j, n) if(i >> j & 1){
      for(int k = j + 1; k < n; k++) if(i >> k & 1){
        ll d = (x[j]-x[k])*(x[j]-x[k]) + (y[j]-y[k])*(y[j]-y[k]);
        chmax(dist[i], d);
      }
    }
  }
  vector<vector<ll>> dp(k + 1, vector<ll>(1 << n, 1e18));
  rep(i, 1 << n) dp[1][i] = dist[i];
  for(int i = 1; i < k; i++){
    for(int s = 1; s < (1 << n); s++){
      for(int t = (1 << n) - 1; t > 0; t--){
        t &= s;
        chmin(dp[i + 1][s], max(dp[i][s & ~t], dist[t]));
      }
    }
  }
  cout << dp[k][(1 << n) - 1] << "\n";
}