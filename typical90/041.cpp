#include <iostream>
#include <vector>
#include <algorithm>
using ll = long long;
using namespace std;

//90[ms]
template <class T>
struct point {
  T x,y;
  point operator+=(const point &a){
    x += a.x; y += a.y;
    return *this;
  }
  point operator-=(const point &a){
    x -= a.x; y -= a.y;
    return *this;
  }
  point operator+(const point &a) const{ return point(*this) += a; }
  point operator-(const point &a) const{ return point(*this) -= a; }
  bool operator<(const point &a) const{
    if(x != a.x) return x < a.x;
    return y < a.y;
  }
  T det(const point &a) const{
    return x * a.y - y * a.x;
  }
};
template<class T>
T gcd(T a, T b){
  if(b == 0) return a;
  return gcd(b, a % b);
}
int main(){
  int n;
  cin >> n;
  vector<point<ll>> pos(n);
  for(int i = 0; i < n; i++){
    ll x,y; cin >> x >> y;
    pos[i] = {x, y};
  }
  sort(pos.begin(), pos.end());
  vector<point<ll>> g(2*n);
  int k = 0;
  for(int i = 0; i < n; i++){
    while(k > 1 && (g[k-1] - g[k-2]).det(pos[i] - g[k-1]) <= 0) k--;
    g[k++] = pos[i];
  }
  for(int i = n - 2, t = k; i >= 0; i--){
    while(k > t && (g[k-1] - g[k-2]).det(pos[i] - g[k-1]) <= 0) k--;
    g[k++] = pos[i];
  }
  g.resize(--k);
  ll edges = k;
  for(int i = 0; i < k; i++){
    ll dx = abs(g[i].x - g[(i+1) % k].x);
    ll dy = abs(g[i].y - g[(i+1) % k].y);
    edges += gcd(dx, dy) - 1;
  }
  ll s = 0;
  for(int i = 0; i < k; i++)
    s += (g[i].x - g[(i+1) % k].x) * (g[i].y + g[(i+1) % k].y);
  s = abs(s);
  //s = a + b / 2 - 1 <=> 2s = 2a + b - 2 <=> 2a + b = 2s + 2 <=> 2(a + b) = (2s + 2 + b) / 2
  ll ans = s + 2 + edges;
  cout << ans / 2 - n << "\n";
}