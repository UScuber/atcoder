#include <iostream>
#include <vector>
#include <algorithm>
using ll = long long;
using namespace std;
const ll inf = 3000000000;

//237[ms]
int main(){
  int n,q;
  cin >> n >> q;
  ll mxx = -inf, mxy = -inf;
  ll mnx = inf, mny = inf;
  vector<ll> x(n), y(n);
  for(int i = 0; i < n; i++){
    int X,Y;
    cin >> X >> Y;
    x[i] = X + Y;
    y[i] = X - Y;
    mxx = max(mxx, x[i]);
    mnx = min(mnx, x[i]);
    mxy = max(mxy, y[i]);
    mny = min(mny, y[i]);
  }
  for(int i = 0; i < q; i++){
    int t; cin >> t;
    t--;
    ll ans = max({mxx-x[t], x[t]-mnx, mxy-y[t], y[t]-mny});
    cout << ans << "\n";
  }
}