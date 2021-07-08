#include <iostream>
using ll = long long;
using namespace std;

//7[ms]
template<class T>
T gcd(T a, T b){
  if(!b) return a;
  return gcd(b, a % b);
}
int main(){
  ll a,b,c;
  cin >> a >> b >> c;
  ll d = gcd(a, gcd(b, c));
  cout << (a+b+c) / d - 3 << "\n";
}