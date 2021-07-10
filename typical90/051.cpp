#include <iostream>
#include <vector>
#include <algorithm>
using ll = long long;
#define rep(i, n) for(int i = 0; i < n; i++)
#define all(a) (a).begin(), (a).end()
using namespace std;

//220[ms]
int main(){
  int n,k; ll p;
  cin >> n >> k >> p;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  int l = n / 2, r = n/2 + (n&1);
  vector<vector<ll>> val(k + 1);
  rep(i, 1 << l){
    int cnt = 0; ll v = 0;
    rep(j, l) if(i >> j & 1){
      cnt++;
      v += a[j];
    }
    if(v > p || cnt > k) continue;
    val[cnt].push_back(v);
  }
  rep(i, k+1) sort(all(val[i]));
  ll ans = 0;
  rep(i, 1 << r){
    int cnt = 0; ll v = 0;
    rep(j, r) if(i >> j & 1){
      cnt++;
      v += a[l + j];
    }
    if(v > p || cnt > k) continue;
    int pos = upper_bound(all(val[k-cnt]), p-v) - val[k-cnt].begin();
    ans += pos;
  }
  cout << ans << "\n";
}