#include <iostream>
#include <string>
#include <vector>

//8[ms]
#define rep(i, n) for(int i = 0; i < n; i++)
using ll = long long;
#define mod 1000000007
using namespace std;

int main(){
  ll l,r;
  cin >> l >> r;
  ll ans = 0;
  vector<ll> d(19, 1);
  rep(i, 18) d[i + 1] = d[i] * 10;
  int temp = to_string(r).size();
  for(ll num = to_string(l).size(); num <= temp; num++){
    ll left = r;
    if(num != 19){
      left = min(r, d[num]);
      if(left == d[num]) left--;
    }
    left %= mod;
    ll right = max(l, d[num - 1]) % mod;
    ll v = left*(left+1)%mod - right*(right-1)%mod;
    v *= 500000004; v %= mod; //2の逆元
    v *= num; v %= mod;
    if(v < 0) v += mod;
    ans += v;
    ans %= mod;
  }
  cout << ans << "\n";
}