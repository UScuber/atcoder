#include <iostream>
using ll = long long;
using namespace std;

//9[ms]
const ll inf = 1000000000000000000;
ll gcd(ll a, ll b){
  if(!b) return a;
  return gcd(b, a % b);
}
int main(){
  ll a,b;
  cin >> a >> b;
  a /= gcd(a, b);
  if(b <= inf / a) cout << a * b << "\n";
  else cout << "Large\n";
}