#include <iostream>
#include <vector>

//116[ms]
#define rep(i, n) for(int i = 0; i < n; i++)
using ll = long long;
using namespace std;

int main(){
  int n,d;
  cin >> n >> d;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  ll ans = 0;
  for(int i = 0; i < (1 << n); i++){
    ll v = 0;
    int cnt = 0;
    rep(j, n) if(i >> j & 1){
      v |= a[j];
      cnt++;
    }
    int cnt2 = 0;
    rep(j, d) if(!(v >> j & 1)) cnt2++;
    if(cnt & 1) ans -= 1LL << cnt2;
    else ans += 1LL << cnt2;
  }
  cout << ans << "\n";
}