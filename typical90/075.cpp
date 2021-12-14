#include <iostream>
#include <cmath>

//20[ms]
using ll = long long;
using namespace std;

int main(){
  ll n;
  cin >> n;
  int cnt = 0;
  for(ll i = 2; i*i <= n; i++){
    while(n % i == 0){
      n /= i;
      cnt++;
    }
  }
  if(n > 1) cnt++;
  int ans = 0;
  while(cnt >> (ans+1)) ans++;
  if(cnt - (1LL << ans) > 0) ans++;
  cout << ans << "\n";
}