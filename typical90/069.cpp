#include <iostream>
using ll = long long;
#define mod 1000000007
using namespace std;

//8[ms]
ll modPow(ll a, ll n, ll p){
  if(!n) return 1;
  if(n == 1) return a % p;
  if(n & 1) return (a * modPow(a, n - 1, p)) % p;
  ll t = modPow(a, n / 2, p);
  return (t * t) % p;
}
int main(){
  ll n,k;
  cin >> n >> k;
  if(min(3LL, n) > k) cout << "0\n";
  else if(n == 1) cout << k << "\n";
  else{
    ll ans = (k * (k - 1)) % mod;
    ans *= modPow(k - 2, n - 2, mod);
    cout << ans % mod << "\n";
  }
}