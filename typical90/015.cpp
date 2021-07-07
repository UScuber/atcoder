#include <iostream>
#include <vector>
using ll = long long;
#define mod 1000000007
using namespace std;

//34[ms]
struct mint{
  ll x;
  mint(ll x = 0) : x((x + mod) % mod){}
  mint operator-() const{ return mint(-x); }
  mint operator+=(const mint &a){
    if((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint &operator++(){
    if(++x == mod) x = 0;
    return *this;
  }
  mint operator++(int){
    mint temp = *this;
    if(++x == mod) x = 0;
    return temp;
  }
  mint &operator-=(const mint &a){
    if((x -= a.x) < 0) x += mod;
    return *this;
  }
  mint &operator--(){
    if(--x < 0) x += mod;
    return *this;
  }
  mint operator--(int){
    mint temp = *this;
    if(--x < 0) x += mod;
    return temp;
  }
  mint &operator*=(const mint &a){
    (x *= a.x) %= mod;
    return *this;
  }
  mint operator+(const mint &a) const{ return mint(*this) += a; }
  mint operator-(const mint &a) const{ return mint(*this) -= a; }
  mint operator*(const mint &a) const{ return mint(*this) *= a; }
  mint pow(ll t) const{
    if(!t) return 1;
    mint a = pow(t >> 1);
    a *= a;
    if (t & 1) a *= *this;
    return a;
  }
  mint inv() const{ return pow(mod - 2); }
  mint &operator/=(const mint &a){ return (*this) *= a.inv(); }
  mint operator/(const mint &a) const{ return mint(*this) /= a; }
  friend istream &operator>>(istream &is, mint &a){ return is >> a.x; }
  friend ostream &operator<<(ostream &os, const mint &a){ return os << a.x; }
};
const int len = 100010;
vector<mint> fact(len), invfact(len);
mint choose(int n, int r){
  return fact[n] * invfact[n - r] * invfact[r];
}

int main(){
  fact[0] = fact[1] = 1;
  for(int i = 2; i < len; i++) fact[i] = fact[i - 1] * i;
  invfact[len - 1] = fact[len - 1].inv();
  for(int i = len - 2; i >= 0; i--) invfact[i] = invfact[i + 1] * (i + 1);

  int n;
  cin >> n;
  for(int k = 1; k <= n; k++){
    mint ans = 0;
    for(int j = 1; (j-1)*k+1 <= n; j++){
      int num = n - ((j-1)*k + 1);
      //j+1 H num
      ans += choose(j + num, j);
    }
    cout << ans << "\n";
  }
}