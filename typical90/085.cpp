#include <iostream>

//285[ms]
using ll = long long;
using namespace std;

int main(){
  ll k;
  cin >> k;
  int ans = 0;
  for(ll i = 1; i*i*i <= k; i++){
    if(k % i) continue;
    ll v = k / i;
    for(ll j = i; j*j <= v; j++){
      if(v % j == 0 && v / j >= j) ans++;
    }
  }
  cout << ans << "\n";
}