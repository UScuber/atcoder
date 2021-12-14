#include <iostream>
#include <vector>

//18[ms]
#define rep(i, n) for(int i = 0; i < n; i++)
using ll = long long;
using namespace std;

int main(){
  int h,w;
  cin >> h >> w;
  vector<vector<ll>> a(h, vector<ll>(w)), b(h, vector<ll>(w));
  rep(i, h) rep(j, w) cin >> a[i][j];
  rep(i, h) rep(j, w) cin >> b[i][j];
  ll ans = 0;
  rep(i, h - 1) rep(j, w - 1){
    ll t = b[i][j] - a[i][j];
    a[i + 1][j] += t;
    a[i][j + 1] += t;
    a[i + 1][j + 1] += t;
    ans += abs(t);
  }
  rep(i, h) if(a[i][w - 1] != b[i][w - 1]){
    cout << "No\n";
    return 0;
  }
  rep(j, w) if(a[h - 1][j] != b[h - 1][j]){
    cout << "No\n";
    return 0;
  }
  cout << "Yes\n";
  cout << ans << "\n";
}