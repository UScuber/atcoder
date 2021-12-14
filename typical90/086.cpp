#include <iostream>
#include <vector>

//22[ms]
#define rep(i, n) for(int i = 0; i < n; i++)
using ll = long long;
#define mod 1000000007
using namespace std;

int main(){
  int n,q;
  cin >> n >> q;
  vector<int> x(q), y(q), z(q);
  vector<ll> w(q);
  rep(i, q){
    cin >> x[i] >> y[i] >> z[i] >> w[i];
    x[i]--; y[i]--; z[i]--;
  }
  ll ans = 1;
  rep(i, 60){
    ll cnt = 0;
    for(int j = 0; j < (1 << n); j++){
      bool ok = true;
      rep(k, q)
        if(((j >> x[k] & 1) | (j >> y[k] & 1) | (j >> z[k] & 1)) == (w[k] >> i & 1));
        else{ ok = false; break; }
      if(ok) cnt++;
    }
    ans *= cnt;
    ans %= mod;
  }
  cout << ans << "\n";
}