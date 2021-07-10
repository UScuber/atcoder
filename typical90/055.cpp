#include <iostream>
#include <vector>
using ll = long long;
using namespace std;

//639[ms]
int main(){
  int n; ll p,q;
  cin >> n >> p >> q;
  vector<ll> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];
  ll ans = 0;
  for(int i = 0; i < n; i++) for(int j = i+1; j < n; j++)
  for(int k = j+1; k < n; k++) for(int l = k+1; l < n; l++){
    ll t = a[i] * a[j]  % p * a[k] % p * a[l] % p;
    for(int s = l+1; s < n; s++){
      if(t * a[s] % p == q) ans++;
    }
  }
  cout << ans << "\n";
}