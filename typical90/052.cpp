#include <iostream>
using ll = long long;
#define mod 1000000007
using namespace std;

//10[ms]
int main(){
  int n;
  cin >> n;
  ll ans = 1;
  for(int i = 0; i < n; i++){
    ll tot = 0;
    for(int j = 0; j < 6; j++){
      int a; cin >> a;
      tot += a;
    }
    ans *= tot;
    ans %= mod;
  }
  cout << ans << "\n";
}