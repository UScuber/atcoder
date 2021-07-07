#include <iostream>
#include <algorithm>
using ll = long long;
using namespace std;

//434[ms]
int main(){
  ll n,a,b,c;
  cin >> n >> a >> b >> c;
  ll ans = 1000000000;
  for(int i = 0; i < 10000; i++){
    for(int j = 0; j < 10000 - i; j++){
      ll num = n - (i * a + j * b);
      if(num >= 0 && num % c == 0){
        ans = min(ans, i + j + num/c);
      }
    }
  }
  cout << ans << "\n";
}